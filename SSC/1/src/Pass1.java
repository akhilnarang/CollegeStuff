import java.io.*;
import java.util.*;

/**
 * Class for our Operands
 */
class Operands {
    String statement, machineCode;

    Operands() {
        this.statement = "";
        this.machineCode = "";
    }

    Operands(String statement, String machineCode) {
        this.statement = statement;
        this.machineCode = machineCode;
    }

    public String getStatement() {
        return this.statement;
    }

    public String getMachineCode() {
        return this.machineCode;
    }

    public Operands createTuple(String statement, String machineCode) {
        return new Operands(statement, machineCode);
    }

    public Map<String, Operands> getOperandTable() {
        Map<String, Operands> operandTable = new HashMap<>();
        operandTable.put("STOP", createTuple("IS", "0"));
        operandTable.put("ADD", createTuple("IS", "1"));
        operandTable.put("SUB", createTuple("IS", "2"));
        operandTable.put("MULT", createTuple("IS", "3"));
        operandTable.put("MOVER", createTuple("IS", "4"));
        operandTable.put("MOVEM", createTuple("IS", "5"));
        operandTable.put("COMP", createTuple("IS", "6"));
        operandTable.put("BC", createTuple("IS", "7"));
        operandTable.put("DIV", createTuple("IS", "8"));
        operandTable.put("READ", createTuple("IS", "9"));
        operandTable.put("PRINT", createTuple("IS", "10"));
        operandTable.put("DC", createTuple("DL", "1"));
        operandTable.put("DS", createTuple("DL", "2"));
        operandTable.put("START", createTuple("AD", "1"));
        operandTable.put("END", createTuple("AD", "2"));
        operandTable.put("ORIGIN", createTuple("AD", "3"));
        operandTable.put("EQU", createTuple("AD", "4"));
        operandTable.put("LTORG", createTuple("AD", "5"));
        operandTable.put("AREG", createTuple("RG", "1"));
        operandTable.put("BREG", createTuple("RG", "2"));
        operandTable.put("CREG", createTuple("RG", "3"));
        operandTable.put("EQ", createTuple("CC", "1"));
        operandTable.put("LT", createTuple("CC", "2"));
        operandTable.put("GT", createTuple("CC", "3"));
        operandTable.put("LE", createTuple("CC", "4"));
        operandTable.put("GE", createTuple("CC", "5"));
        operandTable.put("NE", createTuple("CC", "6"));
        return operandTable;
    }
}

/**
 * Class for our table values
 */
class TableValue {
    int address, index;

    int getAddress() {
        return this.address;
    }

    void setAddress(int address) {
        this.address = address;
    }

    int getIndex() {
        return this.index;
    }

    void setIndex(int index) {
        this.index = index;
    }
}

/**
 * Main class
 */
public class Pass1 {
    public static boolean isOpCode(String token) {
        return (new Operands()).getOperandTable().containsKey(token);
    }

    public static String stringOfTuple(Operands tuple) {
        return "(" + tuple.getStatement() + "," + tuple.getMachineCode() + ") ";
    }

    public static boolean isNumeric(String str) {
        try {
            Double.parseDouble(str);
            return true;
        } catch (NumberFormatException e) {
            return false;
        }
    }

    public static String getTableData(LinkedHashMap<String, TableValue> symbolTable) {
        StringBuilder data = new StringBuilder();
        for (String key : symbolTable.keySet()) {
            data.append(key).append("\t").append(symbolTable.get(key).getAddress()).append("\t").append(symbolTable.get(key).getIndex()).append("\n");
        }
        return data.toString();
    }

    public static int setLiteralTable(int address, LinkedHashMap<String, TableValue> literalTable) {
        for (String key : literalTable.keySet()) {
            TableValue tabValueHolder = literalTable.get(key);
            if (tabValueHolder.getAddress() == 0) {
                tabValueHolder.setAddress(address);
                address++;
            }
        }
        return address;
    }

    static void writeToFile(String data, String filename) throws IOException {
        FileWriter fileWriter = new FileWriter(filename);
        BufferedWriter bufferedWriter = new BufferedWriter(fileWriter);
        bufferedWriter.write(data);
        bufferedWriter.close();
        fileWriter.close();
        System.out.printf("Generated %s%n", filename);
    }

    public static void main(String[] args) throws IOException {
        String filename = "data.txt";
        Map<String, Operands> operandTable = (new Operands()).getOperandTable();
        LinkedHashMap<String, TableValue> symbolTable = new LinkedHashMap<>();
        LinkedHashMap<String, TableValue> literalTable = new LinkedHashMap<>();
        List<Integer> poolTable = new ArrayList<>();
        int symbolTablePointer = 1;
        int literalTablePointer = 1;
        int addressPointer = 0;
        ArrayList<String> intermediateCode = new ArrayList<>();
        try {
            FileReader fileReader = new FileReader(filename);
            BufferedReader bufferedReader = new BufferedReader(fileReader);
            String line;
            StringBuilder intermediateLine = new StringBuilder();

            while ((line = bufferedReader.readLine()) != null) {
                String[] tokens = line.split(" ");
                int tokenCounter = 0;
                if (addressPointer != 0)
                    intermediateLine.append(addressPointer).append(") ");
                for (int i = 0; i < tokens.length; i++) {
                    Operands optuple;
                    String token = tokens[i];
                    if (isOpCode(token)) {
                        optuple = operandTable.get(token);
                        if (token.equals("END")) {
                            intermediateLine = new StringBuilder();
                            intermediateLine.append(stringOfTuple(operandTable.get(token)));
                            addressPointer = setLiteralTable(addressPointer, literalTable);
                            poolTable.add(literalTablePointer);
                            break;
                        }
                        if (token.equals("LTORG")) {
                            intermediateLine = new StringBuilder();
                            addressPointer = setLiteralTable(addressPointer, literalTable);
                            poolTable.add(literalTablePointer);
                        }
                        if (optuple.getStatement().equals("RG") || optuple.getStatement().equals("CC"))
                            intermediateLine.append("(").append(optuple.getMachineCode()).append(") ");
                        else
                            intermediateLine.append(stringOfTuple(optuple));
                        if (token.equals("START")) {
                            try {
                                addressPointer = Integer.parseInt(tokens[i + 1]) - 1;
                                intermediateLine.append("(C,").append(Integer.parseInt(tokens[i + 1])).append(") ");
                            } catch (NumberFormatException e) {
                                System.out.println("Invalid input!");
                                System.exit(1);
                            }
                            i++;
                        } else if (token.equals("ORIGIN")) {
                            TableValue symbolTableItem = symbolTable.get(tokens[i + 1]);
                            addressPointer = symbolTableItem.getAddress();
                            i++;
                        }

                    } else if (symbolTable.containsKey(token)) {
                        intermediateLine.append("(S,").append(symbolTable.get(token).getIndex()).append(") ");
                    } else if (tokenCounter == 0) {
                        TableValue symbolTableItem = new TableValue();
                        symbolTableItem.setAddress(addressPointer);
                        symbolTableItem.setIndex(symbolTablePointer);
                        symbolTable.put(token, symbolTableItem);
                        symbolTablePointer++;
                    } else if (isNumeric(token)) {
                        if (tokens[i - 1].equals("DS")) {
                            TableValue symbolTableItem = new TableValue();
                            symbolTableItem.setAddress(addressPointer);
                            symbolTableItem.setIndex(symbolTable.get(tokens[i - 2]).getIndex());
                            symbolTable.put(tokens[i - 2], symbolTableItem);
                        } else if (tokens[i - 1].equals("DC")) {
                            TableValue symbolTableItem = new TableValue();
                            symbolTableItem.setAddress(addressPointer);
                            symbolTableItem.setIndex(symbolTable.get(tokens[i - 2]).getIndex());
                            symbolTable.put(tokens[i - 2], symbolTableItem);
                        }
                        intermediateLine.append("(C,").append(token).append(") ");
                    } else {
                        if (token.startsWith("=")) {
                            TableValue literalTableHolder = new TableValue();
                            literalTableHolder.setIndex(literalTablePointer);
                            intermediateLine.append("(L,").append(literalTablePointer).append(") ");
                            literalTablePointer++;
                            literalTable.put(token, literalTableHolder);
                        } else {
                            TableValue symbolTableItem = new TableValue();
                            symbolTableItem.setAddress(-1);
                            symbolTableItem.setIndex(symbolTablePointer);
                            symbolTable.put(token, symbolTableItem);
                            intermediateLine.append("(S,").append(symbolTablePointer).append(") ");
                            symbolTablePointer++;
                        }

                    }
                    tokenCounter++;
                }
                addressPointer++;
                intermediateCode.add(intermediateLine.toString());
                intermediateLine = new StringBuilder();
            }
            bufferedReader.close();
            fileReader.close();
        } catch (FileNotFoundException e) {
            System.out.println("FileNotFoundException: " + e.getMessage());
            System.out.println(filename + " does not seem to exist! Exiting.");
            System.exit(1);
        } catch (IOException e) {
            System.out.println(e.getMessage());
            System.exit(1);
        }

        // Write outputs to file with the help of StringBuilder()
        StringBuilder output = new StringBuilder();

        // Consolidate intermediate code
        for (String line : intermediateCode) {
            output.append(line).append("\n");
        }

        // Write intermediate code to a file
        writeToFile(output.toString(), "intermediate_code.txt");

        // Write symbol table to a file
        writeToFile(getTableData(symbolTable), "symbol_table.txt");

        // Write literal table to a file
        writeToFile(getTableData(literalTable), "literal_table.txt");

        // Clear our StringBuilder
        output.setLength(0);

        // Consolidate pool table
        for (int i : poolTable) {
            output.append(i).append("\n");
        }

        // Write pool table to a file
        writeToFile(output.toString(), "pool_table.txt");
    }
}

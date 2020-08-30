import java.io.*;
import java.util.ArrayList;
import java.util.Iterator;
import java.util.Scanner;

class Symbol {
    String name;
    int address;
    int length;

    Symbol(String name, int address, int length) {
        this.name = name;
        this.address = address;
        this.length = length;
    }

    Symbol(Scanner s) {
        this.name = s.next();
        this.address = Integer.parseInt(s.next());
        this.length = Integer.parseInt(s.next());
    }

    void displayRow() {
        System.out.printf("%s\t%d\t%d\n", this.name, this.address, this.length);
    }
}

class Pass2 {

    static ArrayList<Symbol> getSymbolTable() throws FileNotFoundException {
        ArrayList<Symbol> symbolTable = new ArrayList<>();
        Scanner scanner = new Scanner(new File("symbol_table.txt"));
        System.out.println("Reading symbol table!\n\n");
        System.out.println("Name\tAddress\tLength");
        while (scanner.hasNextLine()) {
            Scanner line = new Scanner(scanner.nextLine());
            Symbol symbol = new Symbol(line);
            symbol.displayRow();
            symbolTable.add(symbol);
            line.close();
        }
        scanner.close();
        return symbolTable;
    }

    public static void main(String[] args) throws IOException {
        // Read the symbol table
        ArrayList<Symbol> symbolTable = new ArrayList<>();
        try {
            symbolTable = getSymbolTable();
        } catch (FileNotFoundException e) {
            System.out.printf("%s does not exist here!\n", "symbol_table.txt");
            System.exit(1);
        }

        String input = "data.txt";
        String output = "output.txt";
        Scanner scanner = null;
        try {
            scanner = new Scanner(new File(input));
        } catch (FileNotFoundException e) {
            System.out.printf("%s does not exist here!\n", input);
            System.exit(1);
        }

        FileWriter fileWriter = new FileWriter(output);
        BufferedWriter bufferedWriter = new BufferedWriter(fileWriter);

        // Read from input file
        while (scanner.hasNextLine()) {
            String line = scanner.nextLine();
            String[] words = line.split("\\s+");
            int length = words[1].length();
            String[] instr = words[1].substring(1, length - 1).split(",");
            if (!(instr[0].equals("AD") && (instr[1].equals("1") || instr[1].equals("2")))) {
                String nline = "";
                nline = nline + words[0] + " + ";
                if (instr[0].equals("IS")) {
                    nline = nline + instr[1] + " ";
                    int l2 = words[2].length();
                    String[] arg = words[2].substring(1, l2 - 1).split(",");
                    if (arg[0].equals("S")) {
                        Symbol s = symbolTable.get(Integer.parseInt(arg[1]));
                        nline = nline + s.address + " ";
                    } else {
                        nline = nline + arg[0] + " ";
                    }

                    l2 = words[3].length();
                    arg = words[3].substring(1, l2 - 1).split(",");
                    if (arg[0].equals("S")) {
                        int index = Integer.parseInt(arg[1]) - 1;
                        Symbol s = symbolTable.get(index);
                        nline = nline + s.address + " ";
                    } else {
                        nline = nline + arg[0] + " ";
                    }
                } else if (instr[0].equals("DL") && instr[1].equals("1")) {
                    nline = nline + "00 0 ";
                    int lenx = words[2].length();
                    String[] arg = words[2].substring(1, lenx - 1).split(",");
                    nline = nline + arg[1] + " ";
                }
                bufferedWriter.write(nline);
                bufferedWriter.newLine();
            }
        }
        scanner.close();
    }
}
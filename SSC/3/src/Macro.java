import java.io.*;
import java.util.Vector;

/**
 * Class for Macro Definition Table
 */
class MDT {
    int index;
    String inst;

    MDT(int index, String inst) {
        this.index = index;
        this.inst = inst;
    }

    String getValue() {
        return this.index + "\t" + this.inst + "\n";
    }
}

/**
 * Class for Macro Name Table
 */
class MNT {
    int index, mdt_index;
    String name;
    Vector<String> ala;

    MNT(int index, String name, int mdt_index, Vector<String> ala) {
        this.index = index;
        this.name = name;
        this.mdt_index = mdt_index;
        this.ala = ala;
    }

    String getValue() {
        return this.index + "\t" + this.name + "\t" + this.mdt_index + "\n";
    }

    String getALA(int index) {
        return this.ala.get(index) + "\t";
    }
}

/**
 * Main class
 * Reads input from a text file and parses it to give us MDT, MNT, ALA, and intermediate code
 */
class Macro {

    public static void main(String[] kwargs) throws IOException {
        FileReader fileReader = new FileReader("macro.txt");
        FileWriter fileWriter;
        BufferedReader bufferedReader = new BufferedReader(fileReader);
        BufferedWriter bufferedWriter;
        Vector<MDT> mdt = new Vector<>();
        Vector<MNT> mnt = new Vector<>();
        Vector<String> isc = new Vector<>();
        String line;
        while ((line = bufferedReader.readLine()) != null) {
            // Ensure no leading or trailing spaces
            line = line.trim();

            // Ensure line is not empty
            if (line.isEmpty()) continue;

            // Check whether we have reached a macro definition or not
            if (line.contains("MACRO")) {
                // Read the next time
                line = bufferedReader.readLine();

                // Split on space
                String[] word = line.split("\\s+");

                // Split on comma
                String[] args = word[1].split(",");

                Vector<String> arg = new Vector<>();
                for (String s : args) {
                    // Add argument if it fulfils the condition
                    if (s.contains("=")) arg.addElement(s.substring(0, s.indexOf('=')));
                }

                // Add elements to MNT and MDT
                mnt.addElement(new MNT(mnt.size() + 1, word[0], mdt.size() + 1, arg));
                mdt.addElement(new MDT(mdt.size() + 1, line));

                // Continue reading lines till we reach MEND
                line = bufferedReader.readLine();
                while (!line.equals("MEND")) {
                    if (line.contains("&")) {
                        int i = line.indexOf('&');
                        MNT h = mnt.get(mnt.size() - 1);
                        int j;
                        for (j = 0; j < h.ala.size(); j++) {
                            if (line.substring(i).equals(h.ala.get(j)))
                                break;
                        }
                        mdt.addElement(new MDT(mdt.size() + 1, line.substring(0, i) + "#" + (j + 1)));
                    } else mdt.addElement(new MDT(mdt.size() + 1, line));
                    line = bufferedReader.readLine();
                }
                mdt.addElement(new MDT(mdt.size() + 1, line));
            } else {
                isc.addElement(line);
            }
        }
        bufferedReader.close();
        fileReader.close();

        // Print the MDT and write it to a file as well
        System.out.println("MDT:");
        fileWriter = new FileWriter("MDT.txt");
        bufferedWriter = new BufferedWriter(fileWriter);
        for (MDT word : mdt) {
            System.out.print(word.getValue());
            bufferedWriter.write(word.getValue());
        }
        System.out.println();
        bufferedWriter.close();
        fileWriter.close();


        // Print the MNT and write it to a file as well
        System.out.println("MNT:");
        fileWriter = new FileWriter("MNT.txt");
        bufferedWriter = new BufferedWriter(fileWriter);
        for (MNT word : mnt) {
            System.out.print(word.getValue());
            bufferedWriter.write(word.getValue());
        }
        System.out.println();
        bufferedWriter.close();
        fileWriter.close();


        // Print the ALA and write it to a file as well
        System.out.println("ALA:");
        fileWriter = new FileWriter("ALA.txt");
        bufferedWriter = new BufferedWriter(fileWriter);
        for (MNT word : mnt) {
            for (int j = 0; j < word.ala.size(); j++) {
                System.out.print(word.getALA(j));
                bufferedWriter.write(word.getALA(j));
            }
            bufferedWriter.write("\n");
            System.out.println();
        }
        bufferedWriter.close();
        fileWriter.close();
        System.out.println();

        System.out.println("\nIntermediate code:-");
        fileWriter = new FileWriter("Intermediate.txt");
        bufferedWriter = new BufferedWriter(fileWriter);
        for (String s : isc) {
            System.out.println(s);
            bufferedWriter.write(s + "\n");
        }
        bufferedWriter.close();
        fileWriter.close();
    }
}
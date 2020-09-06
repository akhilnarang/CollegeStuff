import java.io.BufferedReader;
import java.io.FileReader;
import java.util.Vector;


class MDT {
    int index;
    String inst;

    MDT(int index, String inst) {
        this.index = index;
        this.inst = inst;
    }
}

class MNT {
    int index, mdt_index;
    String name;

    MNT(int index, String name, int mdt_index) {
        this.index = index;
        this.name = name;
        this.mdt_index = mdt_index;
    }
}

class MacroPass2 {
    private static int searchMNT(Vector<MNT> a, String b) {
        int i, pos = -1;
        for (i = 0; i < a.size(); i++) {
            if (a.get(i).name.equals(b)) {
                pos = i;
                break;
            }
        }
        return pos;
    }

    public static void main(String[] args) throws Exception {
        Vector<MDT> mdt = new Vector<>();
        Vector<MNT> mnt = new Vector<>();
        Vector<String> isc = new Vector<>();
        String line;
        boolean flag;

        BufferedReader br = new BufferedReader(new FileReader("MDT.txt"));
        while ((line = br.readLine()) != null) {
            String[] row = line.split("\\s+", 2);
            mdt.addElement(new MDT(Integer.parseInt(row[0]), row[1]));
        }
        br.close();

        br = new BufferedReader(new FileReader("MNT.txt"));
        while ((line = br.readLine()) != null) {
            String[] row = line.split("\\s+");
            mnt.addElement(new MNT(Integer.parseInt(row[0]), row[1], Integer.parseInt(row[2])));
        }
        br.close();

        br = new BufferedReader(new FileReader("Intermediate.txt"));
        while ((line = br.readLine()) != null) {
            isc.addElement(line);
        }
        br.close();

        for (String s : isc) {
            String[] instr = s.split("\\s+");

            int loc = searchMNT(mnt, instr[0]);
            if (loc == -1) System.out.println(s);

            else {
                int mdt_ind = mnt.get(loc).mdt_index;
                String[] ala = instr[1].split(",");
                StringBuilder ss = new StringBuilder();
                for (int j = mdt_ind; j < mdt.size(); j++) {
                    flag = false;
                    String inst = mdt.get(j).inst;
                    if (inst.equals("MEND")) break;
                    else {
                        for (int k = 0; k < inst.length(); k++) {
                            if (!flag && inst.charAt(k) != '#') System.out.print(inst.charAt(k));
                            else if (!flag && inst.charAt(k) == '#') flag = true;
                            else if (flag && inst.charAt(k) == ',') {
                                int pos = Integer.parseInt(ss.toString());
                                System.out.print(ala[pos - 1]);
                                ss.delete(0, ss.length());
                                flag = false;
                            } else if (flag) {
                                ss.append(inst.charAt(k));
                            }
                        }
                        if (ss.length() > 0) {
                            int pos = Integer.parseInt(ss.toString());
                            System.out.print(ala[pos - 1]);
                            System.out.println();
                            ss.delete(0, ss.length());
                        }
                    }
                }
            }
        }
    }
}
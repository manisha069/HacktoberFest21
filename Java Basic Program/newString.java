
class main {
    public static void main(String[] args) {
        Scanner in = new Scanner(System.in);
        String str = in.nextLine();
        System.out.println(nCopyString(str));
    }

    static String nCopyString(String s) {
        int n = s.length();
        String base = s.substring(0, 2);

        String str = "";

        for(int i=0; i<n; i++)
            str += base;
            
        return str;
    }
}

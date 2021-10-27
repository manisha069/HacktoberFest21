
class main {
    public static void main(String[] args) {
        Scanner in = new Scanner(System.in);
        String word = in.nextLine();
        String seperator = in.nextLine();
        int count = in.nextInt();
        System.out.println(bigString(word, seperator, count));
    }

    static String bigString(String w, String s, int c) {
        String big = w;
        for(int i = 0; i < c-1; i++) {
            big += s;
            big += w;
        }
        return big;
    }
}

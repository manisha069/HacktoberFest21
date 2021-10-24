
public class Encryption {

    public  void encrypt(String plainText, int shift) {
        char[] arr = plainText.toCharArray();
        int length = plainText.length();
        for (char c : arr) {
            if (c == 'z') {
                c -= 26;
            }
            c += shift;
            System.out.print(c);
        }
    }
}
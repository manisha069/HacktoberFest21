
import java.util.Scanner;

public class Main {

    public static void main(String[] args) {
        Encryption en = new Encryption();
        Decryption dc = new Decryption();
        Scanner myObj = new Scanner(System.in);
        String text = "";

        System.out.println("1 - Encryption\n2 - Decryption\nPlease select an option : ");
        String option = myObj.nextLine();
        System.out.println("Please enter the key : ");
        int key = myObj.nextInt();
        myObj.nextLine();


        switch (option.toLowerCase()) {
            case "1", "encrypt", "encryption" -> {
                System.out.println("Please enter the word to encrypt : ");
                text = myObj.nextLine();
                en.encrypt(text, key);
            }
            case "2", "decrypt", "decryption" -> {
                System.out.println("Please enter the word to decrypt : ");
                text = myObj.nextLine();
                dc.decrypt(text, key);
            }
        }


    }
}


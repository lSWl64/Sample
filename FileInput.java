import java.io.BufferedReader;
import java.io.FileReader;
import java.io.IOException;

public class FileInput {

	public static void main(String[] args) throws IOException {
/*
        BufferedReader br = new BufferedReader(new FileReader("c:\\test\\input.txt"));
        short ch1, ch2, CTR = 0;
        String result;

        while(true) {
        	String line = br.readLine();
        	if(line==null) break;

        	int i=0;
        	while(true) {
        		if(line.charAt(i)=='/')
        			i=line.length()-1;
        		if(i==line.length()) {
        			break;
        		}

        		ch1 = (short) line.charAt(i++);

        		if(line.charAt(i)=='/')
        			i=line.length()-1;
        		if(i==line.length()) {
        			ch2 = 32;
        			result = Integer.toBinaryString(ch1)+Integer.toBinaryString(ch2);
           		 	System.out.print((short) Integer.parseInt(result));
           		 	break;
        		}

        		ch2 = (short) line.charAt(i++);

        		result = Integer.toBinaryString(ch1)+Integer.toBinaryString(ch2);
        		 System.out.print((short) Integer.parseInt(result));



        	}



        }
        */


		 BufferedReader br = new BufferedReader(new FileReader("c:\\test\\input.txt"));
	     short ch1, ch2, CTR = 0;
	     String result;
	     String line = br.readLine();


	}



}

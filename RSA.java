import java.util.Scanner;
import java.math.*;
class RSA {
	public static void main(String args[]) {
		
		int p,q,n,totient,i,e,d=1,t,temp,M,C;
		BigInteger newM,bigN,bigC;
		Scanner sc = new Scanner(System.in);
		
		System.out.println("\n------RSA Algorithm------\n");
		
		//input two prime numbers
		System.out.print("Enter prime numbers p and q: ");
		p = sc.nextInt();
		q = sc.nextInt();
		
		//calculate n
		n = p*q;
		System.out.println("\nn = "+n);
		
		//calculate totient
		totient = (p-1)*(q-1);
		System.out.println("totient(n) = "+totient);
		
		//calculate e
		for(i=2;i<totient;i++) {
			temp = gcd(i,totient);
			if(temp==1)
				break;
		}
		e = i;
		System.out.println("e = "+e);
		
		//calculate d
		for(i=1;i<totient;i++) {
			t = (totient*i) + 1;
			if(t%e==0) {
				d = t/e;
				break;
			}
		}
		System.out.println("d = "+d);
		
		//public key and private key
		System.out.println("\nPublic key: {"+e+", "+n+"}");
		System.out.println("Private key: {"+d+", "+n+"}");
		
		//Encryption using rsa
		System.out.print("\nEnter plain text length M: ");
		M = sc.nextInt();
		C = (int)Math.pow(M,e)%n;
		System.out.println("\nEncrypted message length: "+C);
		
		//Decryption using rsa
		bigN = BigInteger.valueOf(n);
		bigC = BigInteger.valueOf(C);
		newM = (bigC.pow(d)).mod(bigN);
		System.out.println("Decrypted message length: "+newM);
		
	}
	static int gcd(int a, int b) 
    {   
        if (a == 0) 
          return b; 
        if (b == 0) 
          return a; 
       
        if (a == b) 
            return a; 
        
        if (a > b) 
            return gcd(a-b, b); 
        return gcd(a, b-a); 
    } 
}
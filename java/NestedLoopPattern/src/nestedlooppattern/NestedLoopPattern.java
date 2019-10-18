/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */
package nestedlooppattern;

import java.io.BufferedReader;
import java.io.InputStreamReader;
import java.io.IOException;
/**
 *
 * @author akhilnarang
 */
public class NestedLoopPattern {

    /**
     * @param args the command line arguments
     */
    public static void main(String[] args) throws IOException{
        System.out.println("Enter a character to be displayed");
        InputStreamReader isr = new InputStreamReader(System.in);
        BufferedReader stdin = new BufferedReader(isr);
        char c = (char) stdin.read();
        int s = 4;
        for (int i=1;i<=5;i++)
        {
            for (int k=s;k>0;k--)
                System.out.print(" ");
            for (int j=1;j<=i;j++)
                System.out.print(c+" ");
            s--;
            System.out.println();
        }
    }
    
}

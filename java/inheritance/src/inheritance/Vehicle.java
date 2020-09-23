/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */
package inheritance;

/**
 *
 * @author akhilnarang
 */
public class Vehicle {

    public String vehicleType;
    
    public static class Car extends Vehicle {
        
        public String modelType;
        
        public void showDetails()
        {
           vehicleType="Car";
           modelType="Sports";
           System.out.println(modelType+" "+vehicleType);
        }
    }
    
    /**
     * @param args the command line arguments
     */
    public static void main(String[] args) {
        new Car().showDetails();
    }
    
}

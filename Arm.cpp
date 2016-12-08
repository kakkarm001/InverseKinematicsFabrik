
//import java.util.ArrayList;
#include "Vect.h"
#include "Arm.h"
#include "ArmSegment.h"
#include <vector>
#include <string>
#include <iostream>

#define numSegments 3



/**
 *  
 * @author Manish Kakkar
 */
    
   
    // GraphicsContext gc;
    // private Canvas canvas
    Arm::Arm(){
        //for (int i = 0 ; i < 30 ; i++) 
        //    segments.add(new ArmSegment(7.0,0.0,120)) ;
        segments.push_back(ArmSegment(100.0,0.0,150));
        segments.push_back(ArmSegment(80.0,0.0,150));
        segments.push_back(ArmSegment(60.0,0.0,150));
    }
    
    // void setGC(GraphicsContext gc) {
    //     this.gc = gc ;
    // }
    
    void Arm::reset() {
        for(int i=1;i<numSegments;i++){                
            segments[i].setAngle(0);
        }
        //debug
        std::cout << "Arm.reset()\n";
    }

    std::string Arm::toString() {
        return segments.end()->toString();
    }

    void Arm::updateArm() {
        ArmSegment mountPoint(0.0,0.0,0) ;
        for(int i=1;i<numSegments;i++){                
            segments[i].updateEndpoint(mountPoint);

            std::cout << "\n DURING POSITION FOR : " + i;  
            std::cout <<  segments[i].toString() + "\n";
            mountPoint = segments[i];
        }
        // Endpoint arm is endpoint last segement.
        endPoint = segments.end()->endPoint;
     }

    // public void drawArm() {
    //     for(ArmSegment segment: segments) {
    //         segment.drawSegment(gc);
    //     }
         
    // }

    void Arm::setArmAngle(double d,int armIndex) {
        segments.at(armIndex).setAngle(d);
    }

    void Arm::moveEndpointToDest(Vect ep){
        int back = numSegments - 1 ;  // Last arm segment index.
        int loopcount = 0 ;
        
        while (!ep.equals(endPoint)) { 
            if ( loopcount++ == 1000 ) break ;
            while ( back >= 0 ) {
                segments[back].rotateMe(ep, endPoint) ;
                updateArm();
                back-- ;
            }
            //gc.clearRect(0, 0, 600, 250);
            // drawArm() ;
            //INSERT REAL ARM CODE HERE
            
            back = numSegments - 1 ;
           // std::cout << loopcount + "\n";
           // Thread.sleep(20);
            //System.out.println(loopcount);
        }
        //INSTER REAL ARM CODE HERE
        //drawArm();
    }

    // void setCanvas(Canvas canvas) {
    //     this.canvas = canvas ;
    //     this.gc = canvas.getGraphicsContext2D() ;
    // }


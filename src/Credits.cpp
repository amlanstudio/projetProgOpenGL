#include "Credits.hpp"
#include "GLFW/glfw3.h"

State displayCredits(GLuint* texture, glm::vec2 cursorPosition, bool mousePressed){

        printf("x: %f, y: %f \n", cursorPosition.x, cursorPosition.y);

        glPushMatrix();

        glScalef(0.873f, 0.873f, 0.873f);
    
        glEnable(GL_TEXTURE_2D);  // activation du texturing
        glEnable(GL_BLEND);  // activation la transparence
        glBlendFunc(GL_SRC_ALPHA,GL_ONE_MINUS_SRC_ALPHA);  // gere la transparence

        // ----- MON DESSIN -----

        glBindTexture(GL_TEXTURE_2D, texture[18]); //application de ma texture 18
        glColor3f(1.,1.,1.);
        
        //Rules bg
        glPushMatrix();
                
        // glScalef(260,151.5,0);
        glPushMatrix();
        glScalef(260,151.5,0);
        drawSquare();    
        glPopMatrix(); 
        
        //Bouton Return Menu

        if(
                    //hover
                    cursorPosition.x>=875
                    && cursorPosition.x<=1065
                    && cursorPosition.y<=695
                    &&cursorPosition.y>=640
                ){
                        glBindTexture(GL_TEXTURE_2D, texture[12]); //application de ma texture "back" avant hover 

                        glPushMatrix();
                                glTranslatef(70,-65,0);
                                glScalef(50.25,19.625,0);
                                drawSquare();     
                        glPopMatrix();
                

                        if(mousePressed){
                                // TODO fix back to homepage
                            return State::Homepage;
                        }
                }
                else{
                        glBindTexture(GL_TEXTURE_2D, texture[10]); //application de ma texture "back" apres hover 

                        glPushMatrix();
                            glTranslatef(70,-65,0);
                            glScalef(50.25,19.625,0);
                            drawSquare();
                        glPopMatrix();
                }


        glPopMatrix(); 
        glPopMatrix(); 
        return State::Credits;

}
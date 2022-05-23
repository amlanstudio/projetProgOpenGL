#include "Rules.hpp"
#include "GLFW/glfw3.h"

State displayRulespage(GLuint* texture, glm::vec2 cursorPosition, bool mousePressed, int scroll, float width, float height){

        // printf("x: %f, y: %f \n", cursorPosition.x, cursorPosition.y);

        glPushMatrix();

        glScalef(0.873f, 0.873f, 0.873f);
    
        glEnable(GL_TEXTURE_2D);  // activation du texturing
        glEnable(GL_BLEND);  // activation la transparence
        glBlendFunc(GL_SRC_ALPHA,GL_ONE_MINUS_SRC_ALPHA);  // gere la transparence

        // ----- MON DESSIN -----

        glBindTexture(GL_TEXTURE_2D, texture[9]); //application de ma texture 1
        glColor3f(1.,1.,1.);
        
        //Rules bg
        glPushMatrix();

                if(scroll >= -95 && scroll <= 135){
                        // printf("Scroll : %d \n", scroll);
                        glTranslatef(0, scroll, 0);
                } else {
                        if(scroll < -95) {
                                scroll = -95;
                        }
                        if(scroll > 135) scroll = 135;

                        glTranslatef(0, scroll, 0);
                }
                
        // glScalef(260,151.5,0);
        glPushMatrix();
        glScalef(260,351.5,0);
        drawSquare();    
        glPopMatrix(); 
        

        

        
        
        //Bouton Return Menu

        if(
                        //hover
                        scroll > 100
                        && cursorPosition.x>= (543.f/1280.f) * width
                        && cursorPosition.x<= (735.f/1280.f) * width
                        && cursorPosition.y<= (648.f/760.f) * height
                        &&cursorPosition.y>= (592.f/760.f) * height
                ){
                        glBindTexture(GL_TEXTURE_2D, texture[12]); //application de ma texture "back" avant hover 

                        glPushMatrix();
                                glTranslatef(0,-190,0);
                                glScalef(50.25,19.625,0);
                                drawSquare();     
                        glPopMatrix();
                

                        if(mousePressed){
                                // glTranslatef(0, 0, 0);
                                // glBindTexture(GL_TEXTURE_2D, 0);
                                return State::Homepage;
                        }
                }
                else{
                        glBindTexture(GL_TEXTURE_2D, texture[10]); //application de ma texture "back" apres hover 

                        glPushMatrix();
                                glTranslatef(0,-190,0);
                                glScalef(50.25,19.625,0);
                                drawSquare();    
                        glPopMatrix();
                }


        glPopMatrix(); 
        glPopMatrix(); 
        return State::Rules;

}
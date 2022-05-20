#include "GameOver.hpp"

// #include <iostream>
// #include "Window.hpp"
#include "GLFW/glfw3.h"
// #include "glad/glad.h"

// ------ CREATION DE MES FONCTIONS ET LISTES ------ 

State displayGameOver(GLuint* texture, glm::vec2 cursorPosition, bool mousePressed){

        // printf("x: %f, y: %f \n", cursorPosition.x, cursorPosition.y);

        glPushMatrix();

                // glScalef(0.873f, 0.873f, 0.873f);
                glScalef(0.015f, 0.015f, 0.015f);
        
                glEnable(GL_TEXTURE_2D);  // activation du texturing
                glEnable(GL_BLEND);  // activation la transparence

                // action cette commande 
                glBlendFunc(GL_SRC_ALPHA,GL_ONE_MINUS_SRC_ALPHA);  // gere la transparence

                // ----- MON DESSIN -----

                glBindTexture(GL_TEXTURE_2D, texture[16]); //application de ma texture 16 "game over"
                glColor3f(1.,1.,1.);
                
                //Deco bg
                glPushMatrix();
                        glScalef(260,151.5,0);
                        drawSquare();    
                glPopMatrix();  
                
                // bouton yes

                if(
                        //hover
                        cursorPosition.x>=520
                        && cursorPosition.x<=745
                        && cursorPosition.y<=490
                        &&cursorPosition.y>=268
                ){
                        glBindTexture(GL_TEXTURE_2D, texture[15]); //application de ma texture "yes" on hover 

                        glPushMatrix();
                                 glTranslatef(70,-45,0);
                                 glScalef(50.25,19.625,0);
                                 drawSquare();   
                        glPopMatrix();
                

                        if(mousePressed){
                                return State::Game;
                        }
                }
                else{
                        glBindTexture(GL_TEXTURE_2D, texture[14]); //application de ma texture "yes" out hover 

                        glPushMatrix();
                                glTranslatef(70,-45,0);
                                glScalef(50.25,19.625,0);
                                drawSquare();     
                        glPopMatrix();
                }
                

            
                //Bouton No

                if(

                //hover
                        cursorPosition.x>=940 
                        && cursorPosition.x<=1202 
                        && cursorPosition.y<= 680
                        &&cursorPosition.y>= 594
                        ){
                glBindTexture(GL_TEXTURE_2D, texture[13]); //application de ma texture "no" on hover 

                glPushMatrix();
                        glTranslatef(70,-45,0);
                        glScalef(50.25,19.625,0);
                        drawSquare();    
                glPopMatrix();  

                //clic

                if(mousePressed){
                        return State::Quit;
                }

                }
                else{
                        // printf("x: %f, y: %f \n", cursorPosition.x, cursorPosition.y);
                glBindTexture(GL_TEXTURE_2D, texture[11]); //application de ma texture "no" out hover 

                glPushMatrix();
                        glTranslatef(70,-45,0);
                        glScalef(50.25,19.625,0);
                        drawSquare();    
                glPopMatrix();

                }

                // glBindTexture(GL_TEXTURE_2D, 0);
                glDisable(GL_TEXTURE_2D); //desactivation du texturing 


        glPopMatrix();
        
        return State::GameOver;
}
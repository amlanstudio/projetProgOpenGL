#include "Homepage.hpp"

// #include <iostream>
// #include "Window.hpp"
#include "GLFW/glfw3.h"
// #include "glad/glad.h"

// ------ CREATION DE MES FONCTIONS ET LISTES ------ 


// fonction carré

void drawSquare(){
        glBegin(GL_QUADS);
        glTexCoord2f(0,0);
        glVertex2f(-0.5, 0.5);
        glTexCoord2f(1,0);
        glVertex2f(+0.5, +0.5);
        glTexCoord2f(1,1);
        glVertex2f(+0.5, -0.5);
        glTexCoord2f(0,1);
        glVertex2f(-0.5, -0.5);
        glEnd();
}
//------- FIN -----------------------

State displayHomepage(GLuint* texture, glm::vec2 cursorPosition, bool mousePressed, float width, float height){

        // printf("x: %f, y: %f \n", cursorPosition.x, cursorPosition.y);

        glPushMatrix();

                // glScalef(0.873f, 0.873f, 0.873f);
                glScalef(0.015f, 0.015f, 0.015f);
        
                glEnable(GL_TEXTURE_2D);  // activation du texturing
                glEnable(GL_BLEND);  // activation la transparence

                // action cette commande 
                glBlendFunc(GL_SRC_ALPHA,GL_ONE_MINUS_SRC_ALPHA);  // gere la transparence

                // ----- MON DESSIN -----

                glBindTexture(GL_TEXTURE_2D, texture[0]); //application de ma texture 1
                glColor3f(1.,1.,1.);
                
                //Deco bg
                glPushMatrix();
                        glScalef(260,151.5,0);
                        drawSquare();    
                glPopMatrix();  
                
                //Bouton start

                if(
                        //hover
                        cursorPosition.x>= (520.f/1280.f) * width //520
                        && cursorPosition.x<= (745.f/1280.f) * width //745
                        && cursorPosition.y<= (490.f/760.f) * height //490
                        &&cursorPosition.y>= (268.f/760.f) * height //268
                )
                {
                        glBindTexture(GL_TEXTURE_2D, texture[5]); //application de ma texture rules avant hover 

                        glPushMatrix();
                                glTranslatef(0,-4,0);
                                glScalef(52.575,46.41375,0);
                                drawSquare();    
                        glPopMatrix();
                

                        if(mousePressed){
                                return State::Game;
                        }
                }
                else{
                        glBindTexture(GL_TEXTURE_2D, texture[1]); //application de ma texture start apres hover 

                        glPushMatrix();
                                glTranslatef(0,-4,0);
                                glScalef(52.575,46.41375,0);
                                drawSquare();    
                        glPopMatrix();
                }

                

                //Bouton Credit

                if(

                // hover
                        cursorPosition.x>= (80.f/1280.f) * width
                        && cursorPosition.x<= (340.f/1280.f) * width
                        && cursorPosition.y<= (680.f/760.f) * height
                        &&cursorPosition.y>= (594.f/760.f) * height
                ){
                        glBindTexture(GL_TEXTURE_2D, texture[6]); //application de ma texture rules avant hover 

                        glPushMatrix();
                                glTranslatef(-70,-45,0);
                                glScalef(50.25,19.625,0);
                                drawSquare();    
                        glPopMatrix(); 
                        
                        if(mousePressed){
                        return State::Credits ; 
                        }
                }
                else{
                        glBindTexture(GL_TEXTURE_2D, texture[2]); //application de ma texture credit avant hover 

                        glPushMatrix();
                                glTranslatef(-70,-45,0);
                                glScalef(50.25,19.625,0);
                                drawSquare();    
                        glPopMatrix(); 
                }
                

                //Bouton Rules

                if(

                //hover
                        cursorPosition.x>= (510.f/1280.f) * width
                        && cursorPosition.x<= (770.f/1280.f) * width
                        && cursorPosition.y<= (680.f/760.f) * height
                        &&cursorPosition.y>= (594.f/760.f) * height
                ){
                        glBindTexture(GL_TEXTURE_2D, texture[7]); //application de ma texture rules avant hover 

                        glPushMatrix();
                                glTranslatef(0,-45,0);
                                glScalef(50.25,19.625,0);
                                drawSquare();    
                        glPopMatrix();
                
                        if(mousePressed){
                        return State::Rules ; 
                        }

                }     
                else{
                        glBindTexture(GL_TEXTURE_2D, texture[3]); //application de ma texture rules avant hover 

                        glPushMatrix();
                                glTranslatef(0,-45,0);
                                glScalef(50.25,19.625,0);
                                drawSquare();    
                        glPopMatrix();
                }  

                //Bouton Quit

                if(

                //hover
                        cursorPosition.x>= (940.f/1280.f) * width 
                        && cursorPosition.x<= (1202.f/1280.f) * width 
                        && cursorPosition.y<= (680.f/760.f) * height
                        &&cursorPosition.y>= (594.f/760.f) * height
                        ){
                glBindTexture(GL_TEXTURE_2D, texture[8]); //application de ma texture rules après hover 

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
                glBindTexture(GL_TEXTURE_2D, texture[4]); //application de ma texture rules avant hover 

                glPushMatrix();
                        glTranslatef(70,-45,0);
                        glScalef(50.25,19.625,0);
                        drawSquare();    
                glPopMatrix();

                }

                // glBindTexture(GL_TEXTURE_2D, 0);
                glDisable(GL_TEXTURE_2D); //desactivation du texturing 


        glPopMatrix();
        
        return State::Homepage;
}
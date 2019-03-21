#ifndef MODEL_COORDENADA
#define MODEL_COORDENADA

    class Coordenada {
        public:

            /**
             *  Construtor Vazio 
            */
            Coordenada() {}
            
            /**
             *  Construtor com todos os atributos 
             * 
             * @param x int
             *      Coordenada x
             * @param y int
             *      Coordenada y 
            */
            Coordenada(int x, int y) {
                this->x = x;
                this->y = y;
            }

            /**
             *  Construtor Vazio 
             * 
             * @return
             *      Coordenada x 
            */
            int getX() {
                return this->x;
            }

            /**
             *  Construtor Vazio 
             * 
             * @return
             *      Coordenada y
            */
            int getY() {	 	  	 	      	      	    	   	  	  	       	 	
                return this->y;
            }
        private:
            int x;  /**< Coordenada x */
            int y;  /**< Coordenada y */
    };

#endif
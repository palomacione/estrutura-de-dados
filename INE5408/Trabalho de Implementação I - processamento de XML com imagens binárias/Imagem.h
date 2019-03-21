class Image {
        public:
            /**
             * Construtor vazio
             */
            Image() {}

            /**
             * Construtor com todos parâmetros
             * @param name string
             *      Nome da Imagem
             * @param width int
             *      Largura da imagem
             * @param height int
             *      Altura da Imagem
             * @param data string
             *      Conteudo da Imagem
             */
            Image(std::string name, int width, int height, std::string data) {
                this->name = name;
                this->width = width;
                this->height = height;
                this->data = data;
            }

            /**
             * Get nome da imagem
             * @return
             *      Nome da Imagem
             */
            std::string getName() {
                return this->name;
            }

            /**
             * Get largura da imagem
             * @return
             *      Largura da Imagem
             */
            int getWidth() {	 	  	 	      	      	    	   	  	  	       	 	
                return this->width;
            }

            /**
             * Get Altura da imagem
             * @return
             *      Altura da Imagem
             */
            int getHeight() {
                return this->height;
            }

            /**
             * Get conteudo da imagem
             * @return
             *      Conteudo da Imagem
             */
            std::string getData() {
                return this->data;
            }
        private:
            std::string name; /**< Nome da imagem */
            int width; /**< Largura da Imagem */
            int height; /**< Altura da Imagem */
            std::string data; /**< Conteudo da imagem */
    };	 	  	 	      	      	    	   	  	  	       	 	

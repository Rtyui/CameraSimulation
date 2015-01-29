
enum KEYS{W, A, S, D, ESC, NUM_KEYS};

class Keyboard{
private:
		bool keys[NUM_KEYS];
public:
	


	Keyboard(){

	}

	void isEscPressed(bool &redraw, bool &running){
		if(keys[ESC]){
			redraw = false;
			running = false;
		}
	}

	void handleKeyDown(ALLEGRO_EVENT ev){
		switch(ev.keyboard.keycode)
			{
			case ALLEGRO_KEY_W:
				keys[W] = true;
				break;
				
			case ALLEGRO_KEY_A:
				keys[A] = true;
				break;
				
			case ALLEGRO_KEY_S:
				keys[S] = true;
				break;
				
			case ALLEGRO_KEY_D:
				keys[D] = true;
				break;
			
			case ALLEGRO_KEY_ESCAPE:
				keys[ESC] = true;
				break;
			case ALLEGRO_KEY_SPACE:
				break;
			case ALLEGRO_KEY_LSHIFT:
				break;
			}
	}

	void handleKeyUp(ALLEGRO_EVENT ev){
		switch(ev.keyboard.keycode)
			{
			case ALLEGRO_KEY_W:
				keys[W] = false;
				break;
				
			case ALLEGRO_KEY_A:
				keys[A] = false;
				break;
				
			case ALLEGRO_KEY_S:
				keys[S] = false;
				break;
				
			case ALLEGRO_KEY_D:
				keys[D] = false;
				break;
			}
	}

	bool getKey(int index){
		return keys[index];
	}

	bool* getKeys(){
		return keys;
	}


};
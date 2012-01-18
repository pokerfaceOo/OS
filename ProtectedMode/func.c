void drawStand(){
	int videoPointer = 0xB8000, i = 0;
	while(i < 32) {
		*(short int *)videoPointer =  0xFF20;
		videoPointer += 2;
		i++;
		if(i == 16) 
			videoPointer += 128;
	}
	videoPointer += 128;
	while(i < 64) {
		*(short int *)videoPointer =  0x9920;
		videoPointer += 2;
		i++;
		if(i == 48) 
			videoPointer += 128;
	}
	videoPointer += 128;
	while(i < 96) {
		*(short int *)videoPointer =  0xCC20;
		videoPointer += 2;
		i++;
		if(i == 80) 
			videoPointer += 128;
	}
}


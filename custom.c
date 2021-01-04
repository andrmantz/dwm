void
move_mon(const Arg *arg){
	if (!selmon)
		return;

	FILE *cmd=popen("xdotool getmouselocation", "r");
    char result[50];
    int x[4]={0,0,0,0},i;
    if (fgets(result, sizeof(result), cmd) ==NULL){
        perror("Mouse Location\n");
        return;
    }
    
    for (i=0; i<4; i++){
        if (result[2+i] != 32)
            x[i] = result[2+i] - 48;
        else 
            break;
    }
    
    if (i < 4)
        system("xdotool mousemove 2800 1620");
    else{
        i = x[3] + 10*x[2] + 100*x[1] + 1000*x[0];
        if (i < 1920)
            system("xdotool mousemove 2800 1620");
        else 
            system("xdotool mousemove 920 540");
    }

    pclose(cmd);

}

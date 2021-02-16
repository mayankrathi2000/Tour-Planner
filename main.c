#include<graphics.h>
#include<stdio.h>
#include<string.h>
#define INFINITY 9999



int count = 0, MAX=999, abc = 0, cost_o=0 ;

int visited_D[6], visited_C[6], visited_A[6];   

//arrays to store list of cities

char opt_D[7][15] = {"Delhi", "Jaipur", "Udaipur", "Jaisalmer", "Bikaner", "Jodhpur"};     
char opt_C[7][15] = {"Chandigarh", "Jaipur", "Udaipur", "Jaisalmer", "Bikaner", "Jodhpur"};
char opt_A[7][15] = {"Ahmedabad", "Jaipur", "Udaipur", "Jaisalmer", "Bikaner", "Jodhpur"};

char output[7][15];   //output for graphics

char *source_var;

//matrix of distance from delhi to all other cities
int graph_D[6][6] = {
        {0, 235, 663, 756, 426, 621},
        {235, 0, 393, 558, 335, 352},
        {663, 393, 0, 493, 496, 251},
        {756, 558, 493, 0, 330, 282},
        {426, 335, 496, 330, 0, 250},
        {621, 352, 251, 282, 250, 0}};
        
        
//matrix of distance from chandigarh to all other cities        
int graph_C[6][6] = {
        {0, 517, 899, 886, 556, 721},
        {517, 0, 393, 558, 335, 352},
        {899, 393, 0, 493, 496, 251},
        {886, 558, 493, 0, 330, 282},
        {556, 335, 496, 330, 0, 250},
        {721, 352, 251, 282, 250, 0}};
        
        
//matrix of distance from ahmedabad to all other cities       
int graph_A[6][6] = {
        {0, 677, 260, 535, 682, 445},
        {677, 0, 393, 558, 335, 352},
        {260, 393, 0, 493, 496, 251},
        {535, 558, 493, 0, 330, 282},
        {682, 335, 496, 330, 0, 250},
        {445, 352, 251, 282, 250, 0}};


void menu(); 	// main menu 
void loading(); //main loading screen
void about();   //info about developers
void manual();	//guide for user
void h1();      // PRINTS menu heading 
void h2();		// PRINTS menu options 
void h3();		// PRINTS source cities template
void h4();		//PRINTS destination cities template
void delhi();	//printing output of delhi city in TSP
void run_D();	// TSP code for delhi is implemented
void chandigarh();	//printing output of chandigarh city in TSP
void run_C();		// TSP code for chandigarh is implemented
void ahmedabad();	//printing output of ahmedabad city in TSP
void run_A();		// TSP code for ahmedabad is implemented
void roundtrip();	// round trip
void single();		//single trip
void source_tsp();	//selection of source in TSP
void source_dij();	//selection of source in dijkstra
void dest_dij();	//selection of destination in dijkstra
void run_dij();		//dijkstra algo is implemented



int main()
{
	initwindow(2000,2000);
	loading();
	menu();	
}


int find_next_node_D(int node)
{
    
    int nd, min = MAX, min_index, i;
    count++;
    for (i = 0; i < 6; i++)
    {
        if (!visited_D[i] && graph_D[node][i] != 0 && graph_D[node][i] < min)
        {

            min = graph_D[node][i];
            min_index = i;
        }
    }

    nd = min_index;

    if (count == 6)
{
        count=0;
		abc=0;
        delhi();
}

    return nd;
}


void TSP_D(int node)
{

    int i = 0, j = 0;

    int next_node;
    visited_D[node] = 1;

    strcpy(output[abc], opt_D[node]);
    abc++;
    next_node = find_next_node_D(node);

    TSP_D(next_node);
}


void run_D()
{
	
	output[7][15]={};
    int i;
    for (i = 0; i < 6; i++)
    {
        visited_D[i] = 0;
    }

    TSP_D(0);
}


void delhi()
{
setbkcolor(3);
	settextstyle(3,0,6);
	setcolor(0);
	outtextxy(300,50,"THE BEST SUITABLE PATH");
	setcolor(RED);
	bar3d(10,145,1300,150,5,2);
	settextstyle(10,0,3);
	setcolor(5);
	outtextxy(220,590,"!!!!!!!!!!!!PRESS ANY KEY TO GO BACK TO MAIN MENU!!!!!!!!!!!!!");
	setcolor(0);
	settextstyle(5,0,3);
	setfillstyle(9,RED);
	circle(60,350,60);
	floodfill(60,350,0);
	delay(350);
	outtextxy(25,335,output[0]);delay(350);
	line(120,350,240,350);delay(350);
	line(240,350,220,330);delay(350);
	line(240,350,220,370);delay(350);
	setfillstyle(9,RED);
	circle(300,350,60);delay(350);
	floodfill(300,350,0);
	outtextxy(260,335,output[1]);delay(350);
	line(360,350,480,350);delay(350);
	line(480,350,460,330);delay(350);
	line(480,350,460,370);delay(350);
	setfillstyle(9,RED);
	circle(540,350,60);delay(350);
	floodfill(540,350,0);
	outtextxy(500,335,output[2]);delay(350);
	line(600,350,720,350);delay(350);
	line(720,350,700,330);delay(350);
	line(720,350,700,370);delay(350);
	setfillstyle(9,RED);
	circle(780,350,60);delay(350);
	floodfill(780,350,0);
	outtextxy(740,335,output[3]);delay(350);
	line(840,350,960,350);delay(350);
	line(960,350,940,330);delay(350);
	line(960,350,940,370);delay(350);
	setfillstyle(9,RED);
	circle(1020,350,60);delay(350);
	floodfill(1020,350,0);
	outtextxy(980,335,output[4]);delay(350);
	line(1080,350,1200,350);delay(350);
	line(1200,350,1180,330);delay(350);
	line(1200,350,1180,370);delay(350);
	setfillstyle(9,RED);
	circle(1260,350,60);delay(350);
	floodfill(1260,350,0);
	outtextxy(1210,335,output[5]);delay(350);
	line(1260,410,1260,500);delay(350);
	line(1260,500,60,500);delay(350);
	line(60,500,60,410);delay(350);
	line(60,410,40,430);delay(350);
	line(60,410,80,430);delay(350);
	settextstyle(8,0,4);
	setcolor(2);
	outtextxy(120,300,"235 KM");
	outtextxy(360,300,"335 KM");
	outtextxy(600,300,"250 KM");
	outtextxy(840,300,"251 KM");
	outtextxy(1080,300,"493 KM");
	outtextxy(540,450,"756 KM");
	outtextxy(150,200,"THE MINIMUM DISTANCE THAT USER HAVE TO TRAVEL IS: 2,320 KM");
	getch();
	cleardevice();
	menu();		
}


int find_next_node_C(int node)
{
    
    int nd, min = MAX, min_index, i;
    count++;
    for (i = 0; i < 6; i++)
    {
        if (!visited_C[i] && graph_C[node][i] != 0 && graph_C[node][i] < min)
        {

            min = graph_C[node][i];
            min_index = i;
        }
    }

    nd = min_index;

    if (count == 6)
    {
    	count=0;
		abc=0;
        chandigarh();
    }
    return nd;
}


void TSP_C(int node)
{

    int i = 0, j = 0;

    int next_node;
    visited_C[node] = 1;

    strcpy(output[abc], opt_C[node]);
    abc++;
    next_node = find_next_node_C(node);

    TSP_C(next_node);
}


void run_C()
{

    int i;
    output[7][15]={};
    for (i = 0; i < 6; i++)
    {
        visited_C[i] = 0;
    }

    TSP_C(0);
}


void chandigarh()
{
	setbkcolor(3);
	settextstyle(3,0,6);
	setcolor(0);
	outtextxy(300,50,"THE BEST SUITABLE PATH");
	setcolor(RED);
	bar3d(10,145,1300,150,5,2);
	settextstyle(10,0,3);
	setcolor(5);
	outtextxy(220,590,"!!!!!!!!!!!!PRESS ANY KEY TO GO BACK TO MAIN MENU!!!!!!!!!!!!!");
	setcolor(0);
	settextstyle(5,0,3);
	setfillstyle(9,RED);
	circle(62,350,67);delay(350);
	floodfill(62,350,0);
	outtextxy(1,335,output[0]);delay(350);
	line(127,350,240,350);delay(350);
	line(240,350,220,330);delay(350);
	line(240,350,220,370);delay(350);
	setfillstyle(9,RED);
	circle(300,350,60);delay(350);
	floodfill(300,350,0);
	outtextxy(260,335,output[1]);delay(350);
	line(360,350,480,350);delay(350);
	line(480,350,460,330);delay(350);
	line(480,350,460,370);delay(350);
	setfillstyle(9,RED);
	circle(540,350,60);delay(350);
	floodfill(540,350,0);
	outtextxy(500,335,output[2]);delay(350);
	line(600,350,720,350);delay(350);
	line(720,350,700,330);delay(350);
	line(720,350,700,370);delay(350);
	setfillstyle(9,RED);
	circle(780,350,60);delay(350);
	floodfill(780,350,0);
	outtextxy(740,335,output[3]);delay(350);
	line(840,350,960,350);delay(350);
	line(960,350,940,330);delay(350);
	line(960,350,940,370);delay(350);
	setfillstyle(9,RED);
	circle(1020,350,60);delay(350);
	floodfill(1020,350,0);
	outtextxy(980,335,output[4]);delay(350);
	line(1080,350,1200,350);delay(350);
	line(1200,350,1180,330);delay(350);
	line(1200,350,1180,370);delay(350);
	setfillstyle(9,RED);
	circle(1260,350,60);delay(350);
	floodfill(1260,350,0);
	outtextxy(1210,335,output[5]);delay(350);
	line(1260,410,1260,500);delay(350);
	line(1260,500,60,500);delay(350);
	line(60,500,60,415);delay(350);
	line(60,415,40,430);delay(350);
	line(60,415,80,430);delay(350);
	settextstyle(8,0,4);
	setcolor(2);
	outtextxy(127,300,"517 KM");
	outtextxy(360,300,"335 KM");
	outtextxy(600,300,"250 KM");
	outtextxy(840,300,"251 KM");
	outtextxy(1080,300,"493 KM");
	outtextxy(540,450,"886 KM");
	outtextxy(150,200,"THE MINIMUM DISTANCE THAT USER HAVE TO TRAVEL IS: 2,732 KM ");
	getch();
	cleardevice();
	menu();			
}


int find_next_node_A(int node)
{
    
    int nd, min = MAX, min_index, i;
    count++;
    for (i = 0; i < 6; i++)
    {
        if (!visited_A[i] && graph_A[node][i] != 0 && graph_A[node][i] < min)
        {

            min = graph_A[node][i];
            min_index = i;
        }
    }

    nd = min_index;

    if (count == 6)
    {
		count=0;
		abc=0;
        ahmedabad();
    }
    return nd;
}


void TSP_A(int node)
{

    int i = 0, j = 0;

    int next_node;
    visited_A[node] = 1;

    strcpy(output[abc], opt_A[node]);
    abc++;
    next_node = find_next_node_A(node);

    TSP_A(next_node);
}

void run_A()
{

    int i;
    output[7][15]={};
    
    for (i = 0; i < 6; i++)
    {
        visited_A[i] = 0;
    }
    TSP_A(0);
}


void ahmedabad()
{
	setbkcolor(3);
	settextstyle(3,0,6);
	setcolor(0);
	outtextxy(300,50,"THE BEST SUITABLE PATH");
	setcolor(RED);
	bar3d(10,145,1300,150,5,2);
	settextstyle(10,0,3);
	setcolor(5);
	outtextxy(220,590,"!!!!!!!!!!!!PRESS ANY KEY TO GO BACK TO MAIN MENU!!!!!!!!!!!!!");
	setcolor(0);
	settextstyle(5,0,3);
	setfillstyle(9,RED);
	circle(62,350,67);delay(350);
	floodfill(62,350,0);
	outtextxy(1,335,output[0]);delay(350);
	line(127,350,240,350);delay(350);
	line(240,350,220,330);delay(350);
	line(240,350,220,370);delay(350);
	setfillstyle(9,RED);
	circle(300,350,60);delay(350);
	floodfill(300,350,0);
	outtextxy(260,335,output[1]);delay(350);
	line(360,350,480,350);delay(350);
	line(480,350,460,330);delay(350);
	line(480,350,460,370);delay(350);
	setfillstyle(9,RED);
	circle(540,350,60);delay(350);
	floodfill(540,350,0);
	outtextxy(500,335,output[2]);delay(350);
	line(600,350,720,350);delay(350);
	line(720,350,700,330);delay(350);
	line(720,350,700,370);delay(350);
	setfillstyle(9,RED);
	circle(780,350,60);delay(350);
	floodfill(780,350,0);
	outtextxy(740,335,output[3]);delay(350);
	line(840,350,960,350);delay(350);
	line(960,350,940,330);delay(350);
	line(960,350,940,370);delay(350);
	setfillstyle(9,RED);
	circle(1020,350,60);delay(350);
	floodfill(1020,350,0);
	outtextxy(975,335,output[4]);delay(350);
	line(1080,350,1200,350);delay(350);
	line(1200,350,1180,330);delay(350);
	line(1200,350,1180,370);delay(350);
	setfillstyle(9,RED);
	circle(1260,350,60);delay(350);
	floodfill(1260,350,0);
	outtextxy(1220,335,output[5]);delay(350);
	line(1260,410,1260,500);delay(350);
	line(1260,500,60,500);delay(350);
	line(60,500,60,415);delay(350);
	line(60,415,40,430);delay(350);
	line(60,415,80,430);delay(350);
	settextstyle(8,0,4);
	setcolor(2);
	outtextxy(127,300,"260 KM");
	outtextxy(360,300,"251 KM");
	outtextxy(600,300,"250 KM");
	outtextxy(840,300,"330 KM");
	outtextxy(1080,300,"558 KM");
	outtextxy(540,450,"677 KM");
	outtextxy(150,200,"THE MINIMUM DISTANCE THAT USER WANTS TO TRAVEL IS: 2,326 KM");
	getch();
	cleardevice();
	menu();			
}


void run_dij()
{
	int j=0;
	char str[5];
	setbkcolor(3);
	settextstyle(3,0,6);
	setcolor(0);
	outtextxy(300,50,"THE BEST SUITABLE PATH");
	setcolor(RED);
	bar3d(10,145,1300,150,5,2);
	settextstyle(10,0,3);
	setcolor(5);
	outtextxy(220,590,"!!!!!!!!!!!!PRESS ANY KEY TO GO BACK TO MAIN MENU!!!!!!!!!!!!!");
	setcolor(0);
	settextstyle(5,0,3);
	for(int i=0;i<abc;i++)
	{

		circle(65+j,350,65);delay(350);
		floodfill(65+j,350,0);
		j=j+240;
	}
	
	j=0;
	
	for(int i=0;i<abc-1;i++)
	{

	line(130+j,350,240+j,350);delay(350);
	line(240+j,350,220+j,330);delay(350);
	line(240+j,350,220+j,370);delay(350);
	j=j+240;
	}
	
	j=0;
	
	int i=abc-1;
	while(i>=0)
	{
		setfillstyle(9,RED);
		outtextxy(45+j-40,335,output[i]);
		j=j+240;
		i--;	
	}
	
	sprintf(str,"%d",cost_o);
	settextstyle(8,0,4);
	setcolor(2);
	outtextxy(150,200,"THE MINIMUM DISTANCE THAT USER WANTS TO TRAVEL IS:");
	outtextxy(1100,200,str);
	outtextxy(1160,200,"KM");
	abc=0;
	getch();
	cleardevice();
	menu();		
}


void roundtrip()
{
	setbkcolor(3);
	settextstyle(3,0,6);
		setcolor(0);
		outtextxy(280,50,"TRENDING DESTINATIONS");
		
		setfillstyle(9,RED);
		bar3d(10,145,1300,150,5,2);
		
		int i,j;
		
		
		rectangle(20,200,390,380);
		for(i=201;i<380;i++)
		{
			for(j=21;j<390;j++)
			{
				putpixel(j,i,7);
			}
		}
		
		
		rectangle(410,200,1250,380);
		for(i=201;i<380;i++)
		{
			for(j=411;j<1250;j++)
			{
				putpixel(j,i,11);
			}
		}
		
		rectangle(20,400,390,580);
		for(i=401;i<580;i++)
		{
			for(j=21;j<390;j++)
			{
				putpixel(j,i,6);
			}
		}
		
		rectangle(410,400,790,580);
		for(i=401;i<580;i++)
		{
			for(j=411;j<790;j++)
			{
				putpixel(j,i,5);
			}
		}
		
		rectangle(810,400,1250,580);
		for(i=401;i<580;i++)
		{
			for(j=811;j<1250;j++)
			{
				putpixel(j,i,1);
			}
		}
		
		setcolor(8);
		settextstyle(10,0,6);
		outtextxy(105,265,"JAIPUR");
		outtextxy(670,265,"UDAIPUR");
		outtextxy(90,465,"JAISALMER");
		outtextxy(487,465,"BIKANER");
		outtextxy(900,465,"JODHPUR");
		
		settextstyle(10,0,3);
		setcolor(5);
		outtextxy(239,630,"!!!!!!!!!!!!PRESS ANY KEY TO MOVE AHEAD!!!!!!!!!!!!!");
		
		getch();
		cleardevice();
		source_tsp();	
	
}

void single()
{
	source_dij();
		
}


void dijkastra(int G[6][6],int startnode,int destination,int source1)
{
	abc=0;
	output[7][15]={};
    int n=6;
	int cost[7][15],distance[7],pred[7];
	int visited[7],count,mindistance,nextnode,i,j;
	
	//pred[] stores the predecessor of each node
	//count gives the number of nodes seen so far
	//create the cost matrix
	for(i=0;i<n;i++)
		for(j=0;j<n;j++)
			if(G[i][j]==0)
				cost[i][j]=INFINITY;
			else
				cost[i][j]=G[i][j];
	
	//initialize pred[],distance[] and visited[]
	for(i=0;i<n;i++)
	{
		distance[i]=cost[startnode][i];
		pred[i]=startnode;
		visited[i]=0;
	}
	
	distance[startnode]=0;
	visited[startnode]=1;
	count=1;
	
	while(count<n-1)
	{
		mindistance=INFINITY;
		
		//nextnode gives the node at minimum distance
		for(i=0;i<n;i++)
			if(distance[i]<mindistance&&!visited[i])
			{
				mindistance=distance[i];
				nextnode=i;
			}
			
			//check if a better path exists through nextnode			
			visited[nextnode]=1;
			for(i=0;i<n;i++)
				if(!visited[i])
					if(mindistance+cost[nextnode][i]<distance[i])
					{
						distance[i]=mindistance+cost[nextnode][i];
						pred[i]=nextnode;
					}
		count++;
	}
 
	//calculating the path and distance of each node
	for(i=0;i<n;i++)
		if(i!=startnode)
		{
			if(i==destination && source1==0)
			{
			cost_o=distance[i];
			strcpy(output[abc++],opt_D[i]);
			
			
			j=i;
			do
			{
				j=pred[j];
				
				strcpy(output[abc++],opt_D[j]);
			    
			}while(j!=startnode);}
			
			if(i==destination && source1==1)
			{
			cost_o=distance[i];
			strcpy(output[abc++],opt_C[i]);
			
			
			j=i;
			do
			{
				j=pred[j];
				
				strcpy(output[abc++],opt_C[j]);
			    
			}while(j!=startnode);}
			
			if(i==destination && source1==2)
			{
			cost_o=distance[i];
			strcpy(output[abc++],opt_A[i]);
			
			
			j=i;
			do
			{
				j=pred[j];
				
				strcpy(output[abc++],opt_A[j]);
			    
			}while(j!=startnode);}
	}

		run_dij(); //calling run_dij function		
}


void loading() //loading screen
{
	int i,j;
	setbkcolor(3);
	
	for(j=0;j<20;j++) // For Blinking of text
	{
		settextstyle(4,0,8);
		setcolor(j);
		outtextxy(310,100,"Tour Planner");
		delay(100);
	}
	settextstyle(6,0,2);
	outtextxy((getmaxx()/2)-70,getmaxy()-130,"LOADING");
	for(i=0;i<400;i+=2) //loading animation
	{
		setcolor(RED);
		rectangle((getmaxx()/2)-200+i,getmaxy()-100,(getmaxx()/2)+200,getmaxy()-80);
		delay(10);
	}
}


void h1() //prints the "MENU"
	{
		
		settextstyle(3,0,6);
		setcolor(0);
		outtextxy(190,50,"SELECT THE FUNCTION OF YOUR CHOICE");
		setcolor(RED);
		setfillstyle(9,RED);
		bar3d(10,145,1300,150,5,2);
	}
	
	
void h2()  // prints options
	{
		settextstyle(3,0,4);
		setcolor(5);
		outtextxy(220,195,"Round Trip");
		setcolor(1);
		outtextxy(220,235,"Single Trip");
		setcolor(2);
		outtextxy(220,275,"Manual");
		setcolor(14);
		outtextxy(220,315,"About");
		setcolor(4);
		outtextxy(220,355,"Exit");
	}
	
	
void h3() //prints list of source cities
{	
		settextstyle(3,0,6);
		setcolor(0);
		outtextxy(280,50,"SELECT THE SOURCE CITY");
		setcolor(RED);
		bar3d(10,145,1300,150,5,2);
		
		settextstyle(3,0,4);
		setcolor(5);
		outtextxy(220,195,"1.DELHI");
		setcolor(1);
		outtextxy(220,235,"2.CHANDIGARH");
		setcolor(2);
		outtextxy(220,275,"3.AHMEDABAD");
		setcolor(14);
		outtextxy(220,315,"4.MAIN MENU");
}


void h4()  //print list of destination cities
{	
		settextstyle(3,0,6);
		setcolor(0);
		outtextxy(280,50,"SELECT THE DESTINATION CITY");
		setcolor(RED);
		bar3d(10,145,1300,150,5,2);
		
		settextstyle(3,0,4);
		setcolor(5);
		outtextxy(220,195,"1.JAIPUR");
		setcolor(1);
		outtextxy(220,235,"2.UDAIPUR");
		setcolor(2);
		outtextxy(220,275,"3.JAISALMER");
		setcolor(4);
		outtextxy(220,315,"4.BIKANER");
		setcolor(14);
		outtextxy(220,355,"5.JODHPUR");
		
}


void source_dij()  
{
int i,k,x1=210,y1=195,x2=500,y2=230;
	
	while(1)
	{
		setbkcolor(3);
		h3();
		setcolor(RED);
		rectangle(x1,y1,x2,y2);   //cursor

	if(kbhit()) // detects the pressing of key
	{
	   k=getch();
		if(k==72&&y1==195) //cursor at the top
		{
			y1=195+120;     //sends the cursor to bottom
			y2=230+120;
			cleardevice();
			h3();
			setcolor(RED);
			rectangle(x1,y1,x2,y2);
		}
		else if(k==80&&y2==350) //cursor at the bottom and moves to the top
		{
			x1=210; //resets the cursor position to top
			y1=195;
			x2=500;
			y2=230;
			cleardevice();
			h3();
			setcolor(RED);
			rectangle(x1,y1,x2,y2);
		}
		else if(k==80) //cursor moves downward
		{
			cleardevice();
			h3();
			y1=y1+40;
			y2=y2+40;
			rectangle(x1,y1,x2,y2);
		}
		else if(k==72) //cursor moves upward
		{
			cleardevice();
			h3();
			y1=y1-40;
			y2=y2-40;
			setcolor(RED);
			rectangle(x1,y1,x2,y2);
		}

		else if(k==13) //Enter key is pressed
		{
			if(y1==195)  // cursor on the first option
			{
				source_var="Delhi";
				cleardevice();
				dest_dij();
					
			}
			else if(y1==235)  
			{
				source_var="Chandigarh";
				cleardevice();
				dest_dij();
				
			}
			else if(y1==275)
			{
				source_var="Ahmedabad";
				cleardevice();
				dest_dij();
				 
			}
			else if(y1==315)
			{
				cleardevice();
				menu(); 		//return back to main men
			}
			
			
		}
	}
	}		
	
}


void dest_dij()
{
	
	int i,k,x1=210,y1=195,x2=500,y2=230;
	
	while(1)
	{
		setbkcolor(3);
		h4();
		setcolor(RED);
		rectangle(x1,y1,x2,y2);   //cursor

	if(kbhit()) // detects the pressing of key
	{
	   k=getch();
		if(k==72&&y1==195) //cursor at the top
		{
			y1=195+160;     //sends the cursor to bottom
			y2=230+160;
			cleardevice();
			h4();
			setcolor(RED);
			rectangle(x1,y1,x2,y2);
		}
		else if(k==80&&y2==390) //cursor at the bottom and moves to the top
		{
			x1=210; //resets the cursor position to top
			y1=195;
			x2=500;
			y2=230;
			cleardevice();
			h4();
			setcolor(RED);
			rectangle(x1,y1,x2,y2);
		}
		else if(k==80) //cursor moves downward
		{
			cleardevice();
			h4();
			y1=y1+40;
			y2=y2+40;
			rectangle(x1,y1,x2,y2);
		}
		else if(k==72) //cursor moves upward
		{
			cleardevice();
			h4();
			y1=y1-40;
			y2=y2-40;
			setcolor(RED);
			rectangle(x1,y1,x2,y2);
		}

		else if(k==13) //Enter key is pressed
		{
			if(y1==195)  // cursor on the first option
			{
				cleardevice();
				if(source_var=="Delhi")
				dijkastra(graph_D,0,1,0);
				if(source_var=="Chandigarh")
				dijkastra(graph_C,0,1,1);
				if(source_var=="Ahmedabad")
				dijkastra(graph_A,0,1,2);
					
			}
			else if(y1==235)  
			{
				cleardevice();
				if(source_var=="Delhi")
				dijkastra(graph_D,0,2,0);
				if(source_var=="Chandigarh")
				dijkastra(graph_C,0,2,1);
				if(source_var=="Ahmedabad")
				dijkastra(graph_A,0,2,2);
				
			}
			else if(y1==275)
			{
				cleardevice();
				if(source_var=="Delhi")
				dijkastra(graph_D,0,3,0);
				if(source_var=="Chandigarh")
				dijkastra(graph_C,0,3,1);
				if(source_var=="Ahmedabad")
				dijkastra(graph_A,0,3,2);
				 
			}
			else if(y1==315)
			{
				cleardevice();
				if(source_var=="Delhi")
				dijkastra(graph_D,0,4,0);
				if(source_var=="Chandigarh")
				dijkastra(graph_C,0,4,1);
				if(source_var=="Ahmedabad")
				dijkastra(graph_A,0,4,2); 		
			}
			else if(y1==355)
			{
				cleardevice();
				if(source_var=="Delhi")
				dijkastra(graph_D,0,5,0);
				if(source_var=="Chandigarh")
				dijkastra(graph_C,0,5,1);
				if(source_var=="Ahmedabad")
				dijkastra(graph_A,0,5,2); 		
			}
			
			
		}
	}
	}		
	
}


void source_tsp()
{
int i,k,x1=210,y1=195,x2=500,y2=230;
	
	while(1)
	{
		setbkcolor(3);
		h3();
		setcolor(RED);
		rectangle(x1,y1,x2,y2);   //cursor

	if(kbhit()) // detects the pressing of key
	{
	   k=getch();
		if(k==72&&y1==195) //cursor at the top
		{
			y1=195+120;     //sends the cursor to bottom
			y2=230+120;
			cleardevice();
			h3();
			setcolor(RED);
			rectangle(x1,y1,x2,y2);
		}
		else if(k==80&&y2==350) //cursor at the bottom and moves to the top
		{
			x1=210; //resets the cursor position to top
			y1=195;
			x2=500;
			y2=230;
			cleardevice();
			h3();
			setcolor(RED);
			rectangle(x1,y1,x2,y2);
		}
		else if(k==80) //cursor moves downward
		{
			cleardevice();
			h3();
			y1=y1+40;
			y2=y2+40;
			rectangle(x1,y1,x2,y2);
		}
		else if(k==72) //cursor moves upward
		{
			cleardevice();
			h3();
			y1=y1-40;
			y2=y2-40;
			setcolor(RED);
			rectangle(x1,y1,x2,y2);
		}

		else if(k==13) //Enter key is pressed
		{
			if(y1==195)  // cursor on the first option
			{
				cleardevice();
				run_D();
			
			}
			else if(y1==235)  
			{
				cleardevice();
				run_C(); 
			}
			else if(y1==275)
			{
				cleardevice();
				run_A(); 
			}
			else if(y1==315)
			{
				cleardevice();
				menu(); 		//return back to main menu
			}
			
			
		}
	}
	}		
	
}

	
void about()
{
	cleardevice();
	setbkcolor(3);
	settextstyle(4,0,4);
	setcolor(BLUE);
	outtextxy(40,100,"The Developers: ");
	settextstyle(8,0,1);
	setcolor(0);
	outtextxy(40,170,"This Application is a part of Minor Project.");
	outtextxy(40,190,"We have tried to reduce as much technical or logical ");
	outtextxy(40,210,"errors as we can. However, it may contain some bugs.");
	settextstyle(8,0,2);
	outtextxy(40,280,"It is developed by Mayank Rathi, Ritik Ranjan Tripathi, Ritik Kathuria and Shrey Pardal");
	outtextxy(40,300,"students of CSE BAO(B3) Of UPES Dehradun.");
	outtextxy(40,360,"You can mail us your valuable suggestions at : mayankrathi2000@gmail.com ");
	settextstyle(10,0,3);
	setcolor(5);
	outtextxy(40,500,"!!!!!!!!!!!!PRESS ANY KEY TO GO BACK TO MAIN MENU!!!!!!!!!!!!!");
	
	getch();
	cleardevice();	
	
}


void manual()
{		
		
	cleardevice();
	setbkcolor(3);
	settextstyle(4,0,2);
	setcolor(BLUE);
	outtextxy(15,100,"IN THIS APPLICATION WE HAVE GIVEN 2 CHOICES BASED ON YOUR TYPE OF TRAVEL:");
	settextstyle(4,0,3);
	setcolor(WHITE);
	outtextxy(40,150,">  ROUND TRIP");
	settextstyle(8,0,1);
	setcolor(0);
	outtextxy(40,200,"You have to select the city from where you want to start your journey and our application will provide you the shortest");
	outtextxy(40,225,"route possible through which you can travel through all the cities mentioned and return back to your source which you");
	outtextxy(40,250,"have selected and distance of your full journey.");
	settextstyle(4,0,3);
	setcolor(WHITE);
	outtextxy(40,300,">  SINGLE TRIP");
	settextstyle(8,0,1);
	setcolor(0);
	outtextxy(40,350,"You first have to select your source city and then your destination city and the application will give the shortest");
	outtextxy(40,375,"possible route between your source and destination and the distance of your journey.");
	settextstyle(10,0,3);
	setcolor(5);
	outtextxy(40,500,"!!!!!!!!!!!!PRESS ANY KEY TO GO BACK TO MAIN MENU!!!!!!!!!!!!!");
	getch();
	cleardevice();
	
}


void menu()
{
	int i,k,x1=210,y1=195,x2=420,y2=230;
	cleardevice();
	
	while(1)
	{
		setbkcolor(3);
		h1();
		h2();
		setcolor(RED);
		rectangle(x1,y1,x2,y2);   //cursor

	if(kbhit()) // detects the pressing of key
	{
	   k=getch();
		if(k==72&&y1==195) //cursor at the top
		{
			y1=195+160;     //sends the cursor to bottom
			y2=230+160;
			cleardevice();
			h1();
			h2();
			setcolor(RED);
			rectangle(x1,y1,x2,y2);
		}
		else if(k==80&&y2==390) //cursor at the bottom and moves to the top
		{
			x1=210; //resets the cursor position to top
			y1=195;
			x2=420;
			y2=230;
			cleardevice();
			h1();
			h2();
			setcolor(RED);
			rectangle(x1,y1,x2,y2);
		}
		else if(k==80) //cursor moves downward
		{
			cleardevice();
			h1();
			h2();
			y1=y1+40;
			y2=y2+40;
			rectangle(x1,y1,x2,y2);
		}
		else if(k==72) //cursor moves upward
		{
			cleardevice();
			h1();
			h2();
			y1=y1-40;
			y2=y2-40;
			setcolor(RED);
			rectangle(x1,y1,x2,y2);
		}

		else if(k==13) //Enter key is pressed
		{
			if(y1==195)  // cursor on the first option
			{
				cleardevice();
				roundtrip();  //opens the round trip function
				
			}
			else if(y1==235)   
			{
				cleardevice();
				single(); 		//opens the single trip function
			}
			else if(y1==275)
			{
				cleardevice();
				manual(); 	//User Guide Function 
			}
			else if(y1==315)
			{
				cleardevice();
				about(); 		//About
			}
			else if(y1==355)
			{
				exit(0);
				closegraph();  //exit 
			}
		}
	}
}

}

														/*END OF THE CODE*/


























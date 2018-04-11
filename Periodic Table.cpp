//Periodic Table – Source Code
//headers
#include<fstream.h>
#include<iostream.h>
#include<conio.h>
#include<graphics.h>
#include<stdio.h>
#include<dos.h>
#include<stdlib.h>
#include<string.h>
#include<process.h>

//commonly used variables
#define up 72
#define down 80
#define right 77
#define left 75
#define esc 27
#define enter 13

//prototypes
void start();
void output(int a);
void atno();
void border();
void sblock();
void pblock();
void dblock();
void fblock();

//---------------------------------------------------------------------------

struct element
{

	int at_no;
	char sym[3];
	char ele_name[20];
	float at_wt;
	char at_con[150];
	void display()
	{
	cout<<'\n'<<'\n'<<'\n'<<'\n'<<'\n'<<'\n'<<'\n';
		cout<<"\n\tAtomic number: "<<at_no;
		cout<<"\n\n\tSymbol: "<<sym;
		cout<<"\n\n\tName: "<<ele_name;
		cout<<"\n\n\tAtomic weight: "<<at_wt;
		cout<<"\n\n\tElectronic Configuration: "<<at_con;
		border();
	}
}e[118]={{1,"H","Hydrogen",1.008,"1s-1"},
	 {2,"He","Helium",4.003,"1s-2"},
	 {3,"Li","Lithium",6.941,"1s-2 2s-1"},
	 {4,"Be","Beryllium",9.012,"1s-2 2s-2"},
	 {5,"B","Boron",10.811,"1s-2 2s-2 2p-1"},
	 {6,"C","Carbon",12.011,"1s-2 2s-2 2p-2"},
	 {7,"N","Nitrogen",14.007,"1s-2 2s-2 2p-3"},
	 {8,"O","Oxygen",15.999,"1s-2 2s-2 2p-4"},
	 {9,"F","Flourine",18.998,"1s-2 2s-2 2p-5"},
	 {10,"Ne","Neon",20.180,"1s-2 2s-2 2p-6"},
	 {11,"Na","Sodium",22.990,"1s-2 2s-2 2p-6 3s-1"},
	 {12,"Mg","Magnesium",24.305,"1s-2 2s-2 2p-6 3s-2"},
	 {13,"Al","Aluminium",25.982,"1s-2 2s-2 2p-6 3s-2 3p-1"},
	 {14,"Si","Silicon",28.086,"1s-2 2s-2 2p-6 3s-2 3p-2"},
	 {15,"P","Phosphorous",30.974,"1s-2 2s-2 2p-6 3s-2 3p-3"},
	 {16,"S","Sulphur",32.066,"1s-2 2s-2 2p-6 3s-2 3p-4"},
	 {17,"Cl","Chlorine",35.453,"1s-2 2s-2 2p-6 3s-2 3p-5"},
	 {18,"Ar","Argon",39.948,"1s-2 2s-2 2p-6 3s-2 3p-6"},
	 {19,"K","Potassium",39.098,"1s-2 2s-2 2p-6 3s-2 3p-6 4s-1"},
	 {20,"Ca","Calcium",40.078,"1s-2 2s-2 2p-6 3s-2 3p-6 4s-2"},
	 {21,"Sc","Scandium",44.956,"1s-2 2s-2 2p-6 3s-2 3p-6 3d-1 4s-2"},
	 {22,"Ti","Titanium",47.880,"1s-2 2s-2 2p-6 3s-2 3p-6 3d-2 4s-2"},
	 {23,"V","Vanadium",50.942,"1s-2 2s-2 2p-6 3s-2 3p-6 3d-3 4s-2"},
	 {24,"Cr","Chromium",51.996,"1s-2 2s-2 2p-6 3s-2 3p-6 3d-5 4s-1"},
	 {25,"Mn","Manganese",54.938,"1s-2 2s-2 2p-6 3s-2 3p-6 3d-5 4s-2"},
	 {26,"Fe","Iron",55.993,"1s-2 2s-2 2p-6 3s-2 3p-6 3d-6 4s-2"},
	 {27,"Co","Cobalt",58.933,"1s-2 2s-2 2p-6 3s-2 3p-6 3d-7 4s-2"},
	 {28,"Ni","Nickel",58.693,"1s-2 2s-2 2p-6 3s-2 3p-6 3d-8 4s-2"},
	 {29,"Cu","Copper",63.546,"1s-2 2s-2 2p-6 3s-2 3p-6 3d-10 4s-1"},
	 {30,"Zn","Zinc",65.390,"1s-2 2s-2 2p-6 3s-2 3p-6 3d-10 4s-2"},
	 {31,"Ga","Gallium",69.732,"1s-2 2s-2 2p-6 3s-2 3p-6 3d-10 4s-2 4p-1"},
	 {32,"Ge","Germanium",72.610,"1s-2 2s-2 2p-6 3s-2 3p-6 3d-10 4s-2 4p-2"},
	 {33,"As","Arsenic",74.922,"1s-2 2s-2 2p-6 3s-2 3p-6 3d-10 4s-2 4p-3"},
	 {34,"Se","Selenium",78.090,"1s-2 2s-2 2p-6 3s-2 3p-6 3d-10 4s-2 4p-4"},
	 {35,"Br","Bromine",79.904,"1s-2 2s-2 2p-6 3s-2 3p-6 3d-10 4s-2 4p-5"},
	 {36,"Kr","Krypton",84.800,"1s-2 2s-2 2p-6 3s-2 3p-6 3d-10 4s-2 4p-6"},
	 {37,"Rb","Rubidium",84.468,"1s-2 2s-2 2p-6 3s-2 3p-6 3d-10 4s-2 4p-6 5s-1"},
	 {38,"Sr","Strontium",87.620,"1s-2 2s-2 2p-6 3s-2 3p-6 3d-10 4s-2 4p-6 5s-2"},
	 {39,"Y","Yttrium",88.906,"1s-2 2s-2 2p-6 3s-2 3p-6 3d-10 4s-2 4p-6 5s-2 4d-1"},
	 {40,"Zr","Zirconium",91.224,"1s-2 2s-2 2p-6 3s-2 3p-6 3d-10 4s-2 4p-6 5s-2 4d-2"},
	 {41,"Nb","Niobium",92.906,"1s-2 2s-2 2p-6 3s-2 3p-6 3d-10 4s-2 4p-6 5s-1 4d-4"},
	 {42,"Mo","Molybdenum",95.940,"1s-2 2s-2 2p-6 3s-2 3p-6 3d-10 4s-2 4p-6 5s-1 4d-5"},
	 {43,"Tc","Technetium",98.907,"1s-2 2s-2 2p-6 3s-2 3p-6 3d-10 4s-2 4p-6 5s-1 4d-6"},
	 {44,"Ru","Ruthenium",101.070,"1s-2 2s-2 2p-6 3s-2 3p-6 3d-10 4s-2 4p-6 5s-1 4d-7"},
	 {45,"Rh","Rhodium",102.906,"1s-2 2s-2 2p-6 3s-2 3p-6 3d-10 4s-2 4p-6 5s-1 4d-8"},
	 {46,"Pd","Palladium",106.42,"1s-2 2s-2 2p-6 3s-2 3p-6 3d-10 4s-2 4p-6 4d-10"},
	 {47,"Ag","Silver",107.868,"1s-2 2s-2 2p-6 3s-2 3p-6 3d-10 4s-2 4p-6 4d-10 5s-1"},
	 {48,"Cd","Cadmium",112.411,"1s-2 2s-2 2p-6 3s-2 3p-6 3d-10 4s-2 4p-6 4d-10 5s-2"},
	 {49,"In","Indium",114.818,"1s-2 2s-2 2p-6 3s-2 3p-6 3d-10 4s-2 4p-6 4d-10 5s-2 5p-1"},
	 {50,"Sn","Tin",118.710,"1s-2 2s-2 2p-6 3s-2 3p-6 3d-10 4s-2 4p-6 4d-10 5s-2 5p-2"},
	 {51,"Sb","Antimony",121.750,"1s-2 2s-2 2p-6 3s-2 3p-6 3d-10 4s-2 4p-6 4d-10 5s-2 5p-3"},
	 {52,"Te","Tellurium",127.600,"1s-2 2s-2 2p-6 3s-2 3p-6 3d-10 4s-2 4p-6 4d-10 5s-2 5p-4"},
	 {53,"I","Iodine",126.904,"1s-2 2s-2 2p-6 3s-2 3p-6 3d-10 4s-2 4p-6 4d-10 5s-2 5p-5"},
	 {54,"Xe","Xenon",131.290,"1s-2 2s-2 2p-6 3s-2 3p-6 3d-10 4s-2 4p-6 4d-10 5s-2 5p-6"},
	 {55,"Cs","Caesium",132.105,"1s-2 2s-2 2p-6 3s-2 3p-6 3d-10 4s-2 4p-6 4d-10 5s-2 5p-6 6s-1"},
	 {56,"Ba","Barium",137.327,"1s-2 2s-2 2p-6 3s-2 3p-6 3d-10 4s-2 4p-6 4d-10 5s-2 5p-6 6s-2"},
	 {57,"La","Lanthanum",138.906,"1s-2 2s-2 2p-6 3s-2 3p-6 3d-10 4s-2 4p-6 4d-10 5s-2 5p-6 6s-2 5d-1"},
	 {58,"Ce","Cerium",140.115,"1s-2 2s-2 2p-6 3s-2 3p-6 3d-10 4s-2 4p-6 4d-10 5s-2 5p-6 6s-2 4f-2"},
	 {59,"Pr","Praseodymium",140.908,"1s-2 2s-2 2p-6 3s-2 3p-6 3d-10 4s-2 4p-6 4d-10 5s-2 5p-6 6s-2 4f-3"},
	 {60,"Nd","Neodymium",144.240,"1s-2 2s-2 2p-6 3s-2 3p-6 3d-10 4s-2 4p-6 4d-10 5s-2 5p-6 6s-2 4f-4"},
	 {61,"Pm","Promethium",144.193,"1s-2 2s-2 2p-6 3s-2 3p-6 3d-10 4s-2 4p-6 4d-10 5s-2 5p-6 6s-2 4f-5"},
	 {62,"Sm","Samarium",150.360,"1s-2 2s-2 2p-6 3s-2 3p-6 3d-10 4s-2 4p-6 4d-10 5s-2 5p-6 6s-2 4f-6"},
	 {63,"Eu","Europium",151.966,"1s-2 2s-2 2p-6 3s-2 3p-6 3d-10 4s-2 4p-6 4d-10 5s-2 5p-6 6s-2 4f-7"},
	 {64,"Gd","Gadolinium",157.250,"1s-2 2s-2 2p-6 3s-2 3p-6 3d-10 4s-2 4p-6 4d-10 5s-2 5p-6 6s-2 4f-7 5d-1"},
	 {65,"Tb","Terbium",158.925,"1s-2 2s-2 2p-6 3s-2 3p-6 3d-10 4s-2 4p-6 4d-10 5s-2 5p-6 6s-2 4f-9"},
	 {66,"Dy","Dysprosium",162.50,"1s-2 2s-2 2p-6 3s-2 3p-6 3d-10 4s-2 4p-6 4d-10 5s-2 5p-6 6s-2 4f-10"},
	 {67,"Ho","Holmium",164.930,"1s-2 2s-2 2p-6 3s-2 3p-6 3d-10 4s-2 4p-6 4d-10 5s-2 5p-6 6s-2 4f-11"},
	 {68,"Er","Erbium",167.26,"1s-2 2s-2 2p-6 3s-2 3p-6 3d-10 4s-2 4p-6 4d-10 5s-2 5p-6 6s-2 4f-12"},
	 {69,"Tm","Thulium",168.934,"1s-2 2s-2 2p-6 3s-2 3p-6 3d-10 4s-2 4p-6 4d-10 5s-2 5p-6 6s-2 4f-13"},
	 {70,"Yb","Yttrbium",173.040,"1s-2 2s-2 2p-6 3s-2 3p-6 3d-10 4s-2 4p-6 4d-10 5s-2 5p-6 6s-2 4f-14"},
	 {71,"Lu","Lutetium",174.957,"1s-2 2s-2 2p-6 3s-2 3p-6 3d-10 4s-2 4p-6 4d-10 5s-2 5p-6 6s-2 4f-14 5d-1"},
	 {72,"Hf","Hafnium",178.490,"1s-2 2s-2 2p-6 3s-2 3p-6 3d-10 4s-2 4p-6 4d-10 5s-2 5p-6 6s-2 4f-14 5d-2"},
	 {73,"Ta","Tantalum",180.948,"1s-2 2s-2 2p-6 3s-2 3p-6 3d-10 4s-2 4p-6 4d-10 5s-2 5p-6 6s-2 4f-14 5d-3"},
	 {74,"W","Tungsten",183.850,"1s-2 2s-2 2p-6 3s-2 3p-6 3d-10 4s-2 4p-6 4d-10 5s-2 5p-6 6s-2 4f-14 5d-4"},
	 {75,"Re","Rhenium",186.207,"1s-2 2s-2 2p-6 3s-2 3p-6 3d-10 4s-2 4p-6 4d-10 5s-2 5p-6 6s-2 4f-14 5d-5"},
	 {76,"Os","Osmium",190.23,"1s-2 2s-2 2p-6 3s-2 3p-6 3d-10 4s-2 4p-6 4d-10 5s-2 5p-6 6s-2 4f-14 5d-6"},
	 {77,"Ir","Iridium",192.220,"1s-2 2s-2 2p-6 3s-2 3p-6 3d-10 4s-2 4p-6 4d-10 5s-2 5p-6 4f-14 5d-9"},
	 {78,"Pt","Platinum",195.080,"1s-2 2s-2 2p-6 3s-2 3p-6 3d-10 4s-2 4p-6 4d-10 5s-2 5p-6 4f-14 5d-9 6s-1"},
	 {79,"Au","Gold",196.967,"1s-2 2s-2 2p-6 3s-2 3p-6 3d-10 4s-2 4p-6 4d-10 5s-2 5p-6 4f-14 5d-10 6s-1"},
	 {80,"Hg","Mercury",200.590,"1s-2 2s-2 2p-6 3s-2 3p-6 3d-10 4s-2 4p-6 4d-10 5s-2 5p-6 4f-14 5d-10 6s-2"},
	 {81,"Tl","Thallium",204.383,"1s-2 2s-2 2p-6 3s-2 3p-6 3d-10 4s-2 4p-6 4d-10 5s-2 5p-6 4f-14 5d-10 6s-2 6p-1"},
	 {82,"Pb","Lead",207.200,"1s-2 2s-2 2p-6 3s-2 3p-6 3d-10 4s-2 4p-6 4d-10 5s-2 5p-6 4f-14 5d-10 6s-2 6p-2"},
	 {83,"Bi","Bismuth",208.980,"1s-2 2s-2 2p-6 3s-2 3p-6 3d-10 4s-2 4p-6 4d-10 5s-2 5p-6 4f-14 5d-10 6s-2 6p-3"},
	 {84,"Po","Polonium",208.982,"1s-2 2s-2 2p-6 3s-2 3p-6 3d-10 4s-2 4p-6 4d-10 5s-2 5p-6 4f-14 5d-10 6s-2 6p-4"},
	 {85,"At","Astatine",209.987,"1s-2 2s-2 2p-6 3s-2 3p-6 3d-10 4s-2 4p-6 4d-10 5s-2 5p-6 4f-14 5d-10 6s-2 6p-5"},
	 {86,"Rn","Radon",222.018,"1s-2 2s-2 2p-6 3s-2 3p-6 3d-10 4s-2 4p-6 4d-10 5s-2 5p-6 4f-14 5d-10 6s-2 6p-6"},
	 {87,"Fr","Francium",223.020,"1s-2 2s-2 2p-6 3s-2 3p-6 3d-10 4s-2 4p-6 4d-10 5s-2 5p-6 4f-14 5d-10 6s-2 6p-6 7s-1"},
	 {88,"Ra","Radium",226.025,"1s-2 2s-2 2p-6 3s-2 3p-6 3d-10 4s-2 4p-6 4d-10 5s-2 5p-6 4f-14 5d-10 6s-2 6p-6 7s-2"},
	 {89,"Ac","Actinium",227.028,"1s-2 2s-2 2p-6 3s-2 3p-6 3d-10 4s-2 4p-6 4d-10 5s-2 5p-6 4f-14 5d-10 6s-2 6p-6 7s-2 6d-1"},
	 {90,"Th","Thorium",251.080,"1s-2 2s-2 2p-6 3s-2 3p-6 3d-10 4s-2 4p-6 4d-10 5s-2 5p-6 4f-14 5d-10 6s-2 6p-6 7s-2 6d-2"},
	 {91,"Pa","Proactinium",231.036,"1s-2 2s-2 2p-6 3s-2 3p-6 3d-10 4s-2 4p-6 4d-10 5s-2 5p-6 4f-14 5d-10 6s-2 6p-6 6d-1 5f-2"},
	 {92,"U","Uranium",238.029,"1s-2 2s-2 2p-6 3s-2 3p-6 3d-10 4s-2 4p-6 4d-10 5s-2 5p-6 4f-14 5d-10 6s-2 6p-6 6d-1 5f-3"},
	 {93,"Np","Neptunium",237.048,"NA"},
	 {94,"Pu","Plutonium",244.064,"NA"},
	 {95,"Am","Americium",243.061,"NA"},
	 {96,"Cm","Curium",247.070,"NA"},
	 {97,"Bk","Berkelium",247.070,"NA"},
	 {98,"Cf","Californium",251.080,"NA"},
	 {99,"Es","Einsteinium",254.0,"NA"},
	 {100,"Fm","Fermium",257.095,"NA"},
	 {101,"Md","Mendelivium",258.100,"NA"},
	 {102,"No","Nobelium",259.101,"NA"},
	 {103,"Lr","Lawrencium",262.0,"NA"},
	 {104,"Rf","Rutherfordium",261.0,"NA"},
	 {105,"Db","Dubnium",262.0,"NA"},
	 {106,"Sg","Seaborghium",256.0,"NA"},
	 {107,"Bh","Bhorium",264.0,"NA"},
	 {108,"Hs","Hassium",269.0,"NA"},
	 {109,"Mt","Meitnerium",268.0,"NA"},
	 {110,"Ds","Darmstadtium",269.0,"NA"},
	 {111,"Rg","Roentgenium",272.0,"NA"},
	 {112,"Cn","Coppernicium",277.0,"NA"},
	 {113,"Uut","Ununtrium",0,"NA"},
	 {114,"Fl","Flevorium",289.0,"NA"},
	 {115,"Uup","Ununpentium",0,"NA"},
	 {116,"Lv","Livermorium",298.0,"NA"},
	 {117,"Uus","Ununseptium",0,"NA"},
	 {118,"Uuo","Ununoctium",0,"NA"}
};

//---------------------------------------------------------------------------

void start() //first page
{
	clrscr();
	cleardevice();
	border();
	atno();
	char c;

	loop :
	{
	c=getch();
	if(c=='s')
		sblock();
	else if(c=='p')
		pblock();
	else if(c=='d')
		dblock();
	else if(c=='f')
		fblock();
	else if(c==esc)
		{
			cleardevice();
			setcolor(15);
			settextstyle(8,0,3);
			border();
			settextstyle(0,0,2);
			outtextxy(230,100,"THANK YOU !!");
			delay(1000);
			exit(0);
		}
	else { sound(100);
	       delay(50);
	       nosound();
	       goto loop;
	     }
	}
}

//-------------------------------------------------------------------------

void output(int a) //read element list from file, but changed it to structure. No reading actually occurs i guess. :/
{
	cleardevice();
	element ee;
	ifstream f("ele.dat",ios::in|ios::binary);

	while(!f.eof())
	{
	if(f)
	{
		f.read((char*)&ee,sizeof(ee));
		if(a==ee.at_no)
		ee.display();
	}
	}
	f.close();
	gotoxy(15,20);
	cout<<"Please press ENTER key to continue...";
	getch();
	start();
}

//---------------------------------------------------------------------------

void atno() //pt chart
{
	int b=0,c=0,d=0,e=0,f=0,g=0,h=0,i=0,j=0,k=0,l=0,m=0,n=0,o=0,p=0,q=0,r=0;

	for(int ii=0;ii<9;ii++)
	{
		rectangle(51,110+b,111,150+b); b+=40;
		rectangle(81,110+c,141,150+c); c+=40;
		rectangle(111,110+d,171,150+d); d+=40;
		rectangle(141,110+e,204,150+e); e+=40;
		rectangle(171,110+f,231,150+f); f+=40;
		rectangle(204,110+g,261,150+g); g+=40;
		rectangle(231,110+h,291,150+h); h+=40;
		rectangle(261,110+i,321,150+i); i+=40;
		rectangle(291,110+j,351,150+j); j+=40;
		rectangle(321,110+k,381,150+k); k+=40;
		rectangle(351,110+l,411,150+l); l+=40;
		rectangle(381,110+m,441,150+m); m+=40;
		rectangle(411,110+n,471,150+n); n+=40;
		rectangle(441,110+o,504,150+o); o+=40;
		rectangle(471,110+p,531,150+p); p+=40;
		rectangle(504,110+q,561,150+q); q+=40;
		rectangle(531,110+r,591,150+r); r+=40;
	}
	settextstyle(0,0,0);
	outtextxy(246,60,"Atomic Number Chart");
	line(245,75,396,75);
	//numbering
	//p1
	setcolor(12);
	outtextxy(64,127,"1");
	setcolor(7);
	outtextxy(573,127,"2");
	//p2
	setcolor(4);
	outtextxy(64,166,"3");
	setcolor(10);
	outtextxy(94,166,"4");
	setcolor(1);
	outtextxy(424,166,"5");
	setcolor(9);
	outtextxy(454,166,"6");
	outtextxy(484,166,"7");
	outtextxy(514,166,"8");
	setcolor(6);
	outtextxy(544,166,"9");
	setcolor(7);
	outtextxy(570,166,"10");
	//p3
	setcolor(4);
	outtextxy(60,206,"11");
	setcolor(10);
	outtextxy(90,206,"12");
	setcolor(2);
	outtextxy(420,206,"13");
	setcolor(1);
	outtextxy(450,206,"14");
	setcolor(9);
	outtextxy(480,206,"15");
	outtextxy(510,206,"16");
	setcolor(6);
	outtextxy(540,206,"17");
	setcolor(7);
	outtextxy(570,206,"18");
	//p4
	setcolor(4);
	outtextxy(60,246,"19");
	setcolor(10);
	outtextxy(90,246,"20");
	setcolor(14);
	outtextxy(120,246,"21");
	outtextxy(150,246,"22");
	outtextxy(180,246,"23");
	outtextxy(210,246,"24");
	outtextxy(240,246,"25");
	outtextxy(270,246,"26");
	outtextxy(300,246,"27");
	outtextxy(330,246,"28");
	outtextxy(360,246,"29");
	outtextxy(390,246,"30");
	setcolor(2);
	outtextxy(420,246,"31");
	setcolor(1);
	outtextxy(450,246,"32");
	outtextxy(480,246,"33");
	setcolor(9);
	outtextxy(510,246,"34");
	setcolor(6);
	outtextxy(540,246,"35");
	setcolor(7);
	outtextxy(570,246,"36");
	//p5
	setcolor(4);
	outtextxy(60,286,"37");
	setcolor(10);
	outtextxy(90,286,"38");
	setcolor(14);
	outtextxy(120,286,"39");
	outtextxy(150,286,"40");
	outtextxy(180,286,"41");
	outtextxy(210,286,"42");
	outtextxy(240,286,"43");
	outtextxy(270,286,"44");
	outtextxy(300,286,"45");
	outtextxy(330,286,"46");
	outtextxy(360,286,"47");
	outtextxy(390,286,"48");
	setcolor(2);
	outtextxy(420,286,"49");
	outtextxy(450,286,"50");
	setcolor(1);
	outtextxy(480,286,"51");
	outtextxy(510,286,"52");
	setcolor(6);
	outtextxy(540,286,"53");
	setcolor(7);
	outtextxy(570,286,"54");
	//p6
	setcolor(4);
	outtextxy(60,326,"55");
	setcolor(10);
	outtextxy(90,326,"56");
	setcolor(7);
	outtextxy(120,326,"Ln");
	setcolor(14);
	outtextxy(150,326,"72");
	outtextxy(180,326,"73");
	outtextxy(210,326,"74");
	outtextxy(240,326,"75");
	outtextxy(270,326,"76");
	outtextxy(300,326,"77");
	outtextxy(330,326,"78");
	outtextxy(360,326,"79");
	outtextxy(390,326,"80");
	setcolor(2);
	outtextxy(420,326,"81");
	outtextxy(450,326,"82");
	outtextxy(480,326,"83");
	setcolor(1);
	outtextxy(510,326,"84");
	setcolor(6);
	outtextxy(540,326,"85");
	setcolor(7);
	outtextxy(570,326,"86");
	//p7
	setcolor(4);
	outtextxy(60,365,"87");
	setcolor(10);
	outtextxy(90,365,"88");
	setcolor(7);
	outtextxy(120,365,"Ac");
	setcolor(14);
	outtextxy(146,365,"104");
	outtextxy(176,365,"105");
	outtextxy(206,365,"106");
	outtextxy(236,365,"107");
	outtextxy(266,365,"108");
	outtextxy(296,365,"109");
	outtextxy(326,365,"110");
	outtextxy(356,365,"111");
	outtextxy(386,365,"112");
	setcolor(2);
	outtextxy(416,365,"113");
	outtextxy(446,365,"114");
	outtextxy(476,365,"115");
	outtextxy(506,365,"116");
	setcolor(6);
	outtextxy(536,365,"117");
	setcolor(7);
	outtextxy(566,365,"118");
	//Ln-S
	setcolor(13);

	outtextxy(90,405,"57");
	outtextxy(120,405,"58");
	outtextxy(150,405,"59");
	outtextxy(180,405,"60");
	outtextxy(210,405,"61");
	outtextxy(240,405,"62");
	outtextxy(270,405,"63");
	outtextxy(300,405,"64");
	outtextxy(330,405,"65");
	outtextxy(360,405,"66");
	outtextxy(390,405,"67");
	outtextxy(420,405,"68");
	outtextxy(450,405,"69");
	outtextxy(480,405,"70");
	outtextxy(510,405,"71");
	//Ac-S
	setcolor(13);

	outtextxy(90,443,"89");
	outtextxy(120,443,"90");
	outtextxy(150,443,"91");
	outtextxy(180,443,"92");
	outtextxy(210,443,"93");
	outtextxy(240,443,"94");
	outtextxy(270,443,"95");
	outtextxy(300,443,"96");
	outtextxy(330,443,"97");
	outtextxy(360,443,"98");
	outtextxy(388,443,"99");
	outtextxy(418,443,"100");
	outtextxy(448,443,"101");
	outtextxy(478,443,"102");
	outtextxy(508,443,"103");
	//mapping
	//prds
	setcolor(11);
	outtextxy(30,125,"A");
	outtextxy(30,165,"B");
	outtextxy(30,205,"C");
	outtextxy(30,245,"D");
	outtextxy(30,285,"E");
	outtextxy(30,325,"F");
	outtextxy(30,365,"G");
	outtextxy(30,405,"H");
	outtextxy(30,445,"I");
	//gps
	outtextxy(64,90,"1");
	outtextxy(94,90,"2");
	outtextxy(124,90,"3");
	outtextxy(154,90,"4");
	outtextxy(184,90,"5");
	outtextxy(214,90,"6");
	outtextxy(244,90,"7");
	outtextxy(274,90,"8");
	outtextxy(304,90,"9");
	outtextxy(330,90,"10");
	outtextxy(360,90,"11");
	outtextxy(390,90,"12");
	outtextxy(420,90,"13");
	outtextxy(450,90,"14");
	outtextxy(480,90,"15");
	outtextxy(510,90,"16");
	outtextxy(540,90,"17");
	outtextxy(570,90,"18");

}

//------------------------------------------------------------------------

void border()
{
	settextstyle(0,0,0);
	int mi1,mi2;
	rectangle(10,10,getmaxx(),getmaxy());
	rectangle(12,12,getmaxx()-2,getmaxy()-2);
	mi1=getmaxx()/2;

	outtextxy(mi1-50,20,"Periodic Table");
}

//------------------------------------------------------------------------

void sblock()
{
	cleardevice();
	settextstyle(8,0,5);
	setcolor(10);
	outtextxy(300,100,"S-BLOCK");
	int n=0,i=0;         // n-no of blocks and i for coordinates
	setcolor(BLACK);
	for(n=0;n<7;n++)
	{

		if(n==0)
		{
			setfillstyle(1,11);  //color of first box
		}
		else
		{
			setfillstyle(1,12);
		}

		bar(20,20+i,50,50+i);
		delay(50);             //inc y coordinates oy 60
		i+=60;  //60 is standard spacing between two coordinates
	}               //of consequtive boxes
	delay(100);
	i=0;
	for(n=0;n<6;n++)
	{
		setfillstyle(1,13);
		bar(80,80+i,110,110+i);
		delay(50);
		i+=60;
	}
	delay(100);

	// for some reason I need to add a dummy string {"."}
	char ch1[][7]={{"."},{"H"},{"Li"},{"Na"},{"K"},{"Rb"},{"Cs"},{"Fr"}};
	char ch2[][6]={{"."},{"Be"},{"Mg"},{"Ca"},{"Sr"},{"Ba"},{"Ra"}};
	settextstyle(0,0,1);      // declaring 2d string
	for(i=0,n=0;i<=420,n<7;i+=60,n++)
	{
		outtextxy(30,30+i,&ch1[n][7]);
		delay(50);
	}
	delay(100);       // arranging string in their respective boxes
	for(i=0,n=0;i<=360,n<6;i+=60,n++)
	{
		outtextxy(90,90+i,&ch2[n][6]);
		delay(50);
	}
	delay(100);
	n=10;
	for(i=0;i<180;i+=60)      // this is for key
	{
		n++;
		setfillstyle(1,n);
		bar(290,260+i,310,280+i);
		delay(50);
	}
	delay(100);
	settextstyle(2,0,4);       // writing key
	setcolor(WHITE);
	outtextxy(320,260,"Special element");
	outtextxy(320,320,"Alkali metals");
	outtextxy(320,380,"Alkaline Earth metals");
	getch();
//---------------------------------------------------------------------------
	//navigation box (nav_box) starts here
	int x1=18,y1=18,x2=52,y2=52;
	rectangle(x1,y1,x2,y2);          //reference nav_box
	rectangle(x1-1,y1-1,x2+1,y2+1);
	char ch;
	do
	{       // accepting ch in loop
		ch=getch();
		switch(ch)
		{
		case down :  if(y1<=320) //(last coordinate of y1)
			     {
			     setcolor(BLACK); //dissapearing before rect
			     rectangle(x1,y1,x2,y2);
			     rectangle(x1-1,y1-1,x2+1,y2+1);
			     y1+=60;
			     y2+=60;   //inc coord
			     setcolor(WHITE);
			     rectangle(x1,y1,x2,y2); //drawing new rect
			     rectangle(x1-1,y1-1,x2+1,y2+1);

			     }
			     else
			     {
				sound(100);
				delay(50);     //warning
				nosound();
			     }
			     break;

		case up :    if(y1>=70)
			     {
			     setcolor(BLACK);
			     rectangle(x1,y1,x2,y2);
			     rectangle(x1-1,y1-1,x2+1,y2+1);
			     y1-=60;
			     y2-=60;
			     setcolor(WHITE);
			     rectangle(x1,y1,x2,y2);
			     rectangle(x1-1,y1-1,x2+1,y2+1);
			     }
			     else
			     {
				sound(100);
				delay(50);
				nosound();
			     }
			     break;


		case right : if(x1<=20)
			     {
			     setcolor(BLACK);
			     rectangle(x1,y1,x2,y2);
			     rectangle(x1-1,y1-1,x2+1,y2+1);
			     x1+=60;
			     x2+=60;
			     setcolor(WHITE);
			     rectangle(x1,y1,x2,y2);
			     rectangle(x1-1,y1-1,x2+1,y2+1);
			     }
			     else
			     {
				sound(100);
				delay(50);
				nosound();
			     }
			     break;

		case left :  if(x1>=20)
			     {
			     setcolor(BLACK);
			     rectangle(x1,y1,x2,y2);
			     rectangle(x1-1,y1-1,x2+1,y2+1);
			     x1-=60;
			     x2-=60;
			     setcolor(WHITE);
			     rectangle(x1,y1,x2,y2);
			     rectangle(x1-1,y1-1,x2+1,y2+1);
			     }
			     else
			     {
				sound(100);
				delay(50);
				nosound();
			     }
			     break;

		case enter :
				if(x1==18&&y1==18)
					output(1);
				else if(x1==18&&y1==78)
					output(3);
				else if(x1==18&&y1==138)
					output(11);
				else if(x1==18&&y1==198)
					output(19);
				else if(x1==18&&y1==258)
					output(37);
				else if(x1==18&&y1==318)
					output(55);
				else if(x1==18&&y1==378)
					output(87);
				else if(x1==78&&y1==78)
					output(4);
				else if(x1==78&&y1==138)
					output(12);
				else if(x1==78&&y1==198)
					output(20);
				else if(x1==78&&y1==253)
					output(38);
				else if(x1==78&&y1==318)
					output(56);
				else if(x1==78&&y1==378)
					output(88);
				else if(x1==78&&y1==78)
					output(4);
				else if(x1==78&&y1==138)
					output(12);
				else if(x1==78&&y1==198)
					output(20);
				else if(x1==78&&y1==258)
					output(38);
				else if(x1==78&&y1==318)
					output(56);
				else if(x1==78&&y1==378)
					output(88);

				break;

		case esc : start();
				   break;
		}
	}
	while(ch!=esc);      //loop till esc is pressed

	getch();
}

//---------------------------------------------------------------------------

void pblock()
{
	cleardevice();
	settextstyle(8,0,5);
	outtextxy(50,100,"P-BLOCK");
	int n=0,i=0,j,ele=5;
	//1
	for(n=0;n<6;n++)
	{

		setfillstyle(1,11);
		bar(580,20+i,610,50+i);
		delay(50);
		i+=60;
	}
	//2
	delay(100);
	i=0;
	for(n=0;n<5;n++)
	{
		if(n==4)
		{
			setfillstyle(1,YELLOW);
		}
		else
		{
			setfillstyle(1,12);
		}
		bar(520,80+i,550,110+i);
		delay(50);
		i+=60;
	}
	//3
	delay(100);
	i=0;
	for(n=0;n<5;n++)
	{
		if(n<3)
		{
			setfillstyle(1,MAGENTA);
		}
		else if(n>=3&&n<=5)
		{
			setfillstyle(1,LIGHTBLUE);
		}
		bar(460,80+i,490,110+i);
		delay(50);
		i+=60;
	}
	//4
	delay(100);
	i=0;
	for(n=0;n<5;n++)
	{
		if(n<2)
		{
			setfillstyle(1,MAGENTA);
		}
		else if(n<4)
		{
			setfillstyle(1,LIGHTBLUE);
		}
		else
		{
			setfillstyle(1,GREEN);
		}
		bar(400,80+i,430,110+i);
		delay(50);
		i+=60;
	}
	//5
	delay(100);
	i=0;
	for(n=0;n<5;n++)
	{
		if(n==0)
		{
			setfillstyle(1,MAGENTA);
		}
		else if(n>0&&n<3)
		{
			setfillstyle(1,LIGHTBLUE);
		}
		else
		{
			setfillstyle(1,GREEN);
		}
		bar(340,80+i,370,110+i);
		delay(50);
		i+=60;
	}
	//6
	delay(100);
	i=0;
	for(n=0;n<5;n++)
	{
		if(n==0)
		{
			setfillstyle(1,LIGHTBLUE);
		}
		else
		{
			setfillstyle(1,GREEN);
		}
		bar(280,80+i,310,110+i);
		delay(50);
		i+=60;
	}
	//last
	delay(100);
	i=0;
	for(n=0;n<7;n++)
	{
		setfillstyle(1,7);
		bar(280+i,380,310+i,410);
		delay(50);
		i+=60;
	}

	delay(100);
	setcolor(WHITE);
	settextstyle(2,0,4);
	setfillstyle(1,CYAN);
	bar(50,200,60,210);
	outtextxy(70,200,"Noble Gases");
	setfillstyle(1,LIGHTRED);
	bar(50,250,60,260);
	outtextxy(70,250,"Halogens");
	setfillstyle(1,LIGHTBLUE);
	bar(50,300,60,310);
	outtextxy(70,300,"Metalloids");
	setfillstyle(1,GREEN);
	bar(50,350,60,360);
	outtextxy(70,350,"Metals");
	setfillstyle(1,7);
	bar(50,400,60,410);
	outtextxy(70,400,"Man-made elements");
	delay(100);

char ch18[][5]={{"."},{"He"},{"Ne"},{"Ar"},{"Kr"},{"xe"},{"Rn"},{"Uuo"}};
char ch17[][5]={{"."},{"F"},{"Cl"},{"Br"},{"I"},{"At"},{"Uus"}};
char ch16[][5]={{"."},{"O"},{"S"},{"Se"},{"Te"},{"Po"},{"Uuh"}};
char ch15[][5]={{"."},{"N"},{"P"},{"As"},{"Sb"},{"Bi"},{"Uup"}};
char ch14[][5]={{"."},{"C"},{"Si"},{"Ge"},{"Sn"},{"Pb"},{"Uuq"}};
char ch13[][5]={{"."},{"B"},{"Al"},{"Ga"},{"In"},{"Tl"},{"Uut"}};
	setcolor(BLACK);

	settextstyle(0,0,1);
	//1
	for(i=0,n=0;i<=420,n<7;i+=60,n++)
	{
		outtextxy(585,30+i,&ch18[n][5]);
		delay(50);
	}
	//2
	for(i=0,n=0;i<=360,n<6;i+=60,n++)
	{
		outtextxy(525,90+i,&ch17[n][5]);
		delay(50);
	}
	//3
	for(i=0,n=0;i<=360,n<6;i+=60,n++)
	{
		outtextxy(465,90+i,&ch16[n][5]);
		delay(50);
	}
	//4
	for(i=0,n=0;i<=360,n<6;i+=60,n++)
	{
		outtextxy(405,90+i,&ch15[n][5]);
		delay(50);
	}
	//5
	for(i=0,n=0;i<=360,n<6;i+=60,n++)
	{
		outtextxy(345,90+i,&ch14[n][5]);
		delay(50);
	}
	//6
	for(i=0,n=0;i<=360,n<6;i+=60,n++)
	{
		outtextxy(285,90+i,&ch13[n][5]);
		delay(50);
	}
	getch();
		//navigation box ( nav_box ) starts here
	int x1=578,y1=18,x2=612,y2=52;
	rectangle(x1,y1,x2,y2);          //reference nav_box
	rectangle(x1-1,y1-1,x2+1,y2+1);
	char ch;
	do
	{                    // accepting ch in loop
		ch=getch();
		switch(ch)
		{
		case down :  if(y1<=320)//(last coordinate of y1) - 60 ~ appr
			     {
			     setcolor(BLACK);    //dissapearing before rect
			     rectangle(x1,y1,x2,y2);
			     rectangle(x1-1,y1-1,x2+1,y2+1);
			     y1+=60;
			     y2+=60;   //inc coord
			     setcolor(WHITE);
			     rectangle(x1,y1,x2,y2); //drawing new rect
			     rectangle(x1-1,y1-1,x2+1,y2+1);
			     }
			     else
			     {
				sound(100);
				delay(50);     //warning
				nosound();
			     }
			     break;

		case up :    if(y1>=70)
			     {
			     setcolor(BLACK);
			     rectangle(x1,y1,x2,y2);
			     rectangle(x1-1,y1-1,x2+1,y2+1);
			     y1-=60;
			     y2-=60;
			     setcolor(WHITE);
			     rectangle(x1,y1,x2,y2);
			     rectangle(x1-1,y1-1,x2+1,y2+1);
			     }
			     else
			     {
				sound(100);
				delay(50);
				nosound();
			     }
			     break;

		case right : if(x1<=550)
			     {
			     setcolor(BLACK);
			     rectangle(x1,y1,x2,y2);
			     rectangle(x1-1,y1-1,x2+1,y2+1);
			     x1+=60;
			     x2+=60;
			     setcolor(WHITE);
			     rectangle(x1,y1,x2,y2);
			     rectangle(x1-1,y1-1,x2+1,y2+1);
			     }
			     else
			     {
				sound(100);
				delay(50);
				nosound();
			     }
			     break;

		case left :  if(x1>=320)
			     {
			     setcolor(BLACK);
			     rectangle(x1,y1,x2,y2);
			     rectangle(x1-1,y1-1,x2+1,y2+1);
			     x1-=60;
			     x2-=60;
			     setcolor(WHITE);
			     rectangle(x1,y1,x2,y2);
			     rectangle(x1-1,y1-1,x2+1,y2+1);
			     }
			     else
			     {
				sound(100);
				delay(50);
				nosound();
			     }
			     break;

		case enter :    if(x1==578&&y1==18)
				{  output(2);
				}
				else
				{
				ele=5;
				for(i=278,ele;i<=578,ele<=10;i+=60,ele++)
				{
					if(x1==i&&y1==78)
						output(ele);
				}
				ele=13;
				for(i=278,ele;i<=578,ele<=18;i+=60,ele++)
				{
					if(x1==i&&y1==138)
						output(ele);
				}
				ele=31;
				for(i=278,ele;i<=578,ele<=36;i+=60,ele++)
				{
					if(x1==i&&y1==198)
						output(ele);
				}
				ele=49;
				for(i=278,ele;i<=578,ele<=54;i+=60,ele++)
				{
					if(x1==i&&y1==258)
						output(ele);
				}
				ele=81;
				for(i=278,ele;i<=578,ele<=86;i+=60,ele++)
				{
					if(x1==i&&y1==318)
						output(ele);
				}
				ele=113;
				for(i=278,ele;i<=578,ele<=118;i+=60,ele++)
				{
					if(x1==i&&y1==378)
						output(ele);
				}
				}

		case esc : start();
				   break;

		}
	}
	while(ch!=esc);      //loop till esc is pressed

	getch();
}

//------------------------------------------------------------------------

void dblock()
{
	cleardevice();
	settextstyle(8,0,5);
	setcolor(10);
	outtextxy(230,50,"D-BLOCK");
	int n=0,i=0,ele=0;
	int x1=40,y1=200,x2=70,y2=230;
	int x11=50,y11=210;
	setcolor(BLACK);

	char ch3[][5]={{"."},{"Sc"},{"Y"},{"Lu"},{"Lr"}};
	char ch4[][5]={{"."},{"Ti"},{"Zr"},{"Hf"},{"Rf"}};
	char ch5[][5]={{"."},{"V"},{"Nb"},{"Ta"},{"Db"}};
	char ch6[][5]={{"."},{"Cr"},{"Mo"},{"W"},{"Sg"}};
	char ch7[][5]={{"."},{"Mn"},{"Tc"},{"Re"},{"Bh"}};
	char ch8[][5]={{"."},{"Fe"},{"Ru"},{"Os"},{"Hs"}};
	char ch9[][5]={{"."},{"Co"},{"Rh"},{"Ir"},{"Mt"}};
	char ch10[][5]={{"."},{"Ni"},{"Pd"},{"Pt"},{"Ds"}};
	char ch11[][5]={{"."},{"Cu"},{"Ag"},{"Au"},{"Rg"}};
	char ch12[][5]={{"."},{"Zn"},{"Cd"},{"Hg"},{"Cn"}};

    for(int j=0;j<10;j++)
    {

	for(n=0;n<4;n++)
	{
		if(j==0&&(n==2||n==3))
		{
			setfillstyle(1,CYAN);
		}
		else
		{
			setfillstyle(1,YELLOW);
		}
		bar(x1,y1+i,x2,y2+i);
		i+=60;
		delay(50);
	}
	x1+=60;
	x2+=60;
	y1=200;
	y2=230;
	i=0;
    }

	settextstyle(0,0,1);
	for(i=0,n=0;i<=360,n<6;i+=60,n++)
	{
		outtextxy(x11,y11+i,&ch3[n][5]);
		delay(50);
	}
	x11+=60;
	for(i=0,n=0;i<=360,n<6;i+=60,n++)
	{
		outtextxy(x11,y11+i,&ch4[n][5]);
		delay(50);
	}
	x11+=60;
	for(i=0,n=0;i<=360,n<6;i+=60,n++)
	{
		outtextxy(x11,y11+i,&ch5[n][5]);
		delay(50);
	}
	x11+=60;
	for(i=0,n=0;i<=360,n<6;i+=60,n++)
	{
		outtextxy(x11,y11+i,&ch6[n][5]);
		delay(50);
	}
	x11+=60;
	for(i=0,n=0;i<=360,n<6;i+=60,n++)
	{
		outtextxy(x11,y11+i,&ch7[n][5]);
		delay(50);
	}
	x11+=60;
	for(i=0,n=0;i<=360,n<6;i+=60,n++)
	{
		outtextxy(x11,y11+i,&ch8[n][5]);
		delay(50);
	}
	x11+=60;
	for(i=0,n=0;i<=360,n<6;i+=60,n++)
	{
		outtextxy(x11,y11+i,&ch9[n][5]);
		delay(50);
	}
	x11+=60;
	for(i=0,n=0;i<=360,n<6;i+=60,n++)
	{
		outtextxy(x11,y11+i,&ch10[n][5]);
		delay(50);
	}
	x11+=60;
	for(i=0,n=0;i<=360,n<6;i+=60,n++)
	{
		outtextxy(x11,y11+i,&ch11[n][5]);
		delay(50);
	}
	x11+=60;
	for(i=0,n=0;i<=360,n<6;i+=60,n++)
	{
		outtextxy(x11,y11+i,&ch12[n][5]);
		delay(50);
	}

	//nav_box
	x11=38;
	y11=198;
	int x22=72,y22=232;
	rectangle(x11,y11,x22,y22);
	rectangle(x11-1,y11-1,x22+1,y22+1);
	char ch;
	do
	{                    // accepting ch in loop
		ch=getch();
		switch(ch)
		{
		case down :  if(y11<=320)//(last coordinate of y1) - 60 ~ appr
			     {
			     setcolor(BLACK);    //dissapearing before rect
			     rectangle(x11,y11,x22,y22);
			     rectangle(x11-1,y11-1,x22+1,y22+1);
			     y11+=60;
			     y22+=60;   //inc coord
			     setcolor(WHITE);
			     rectangle(x11,y11,x22,y22); //drawing new rect
			     rectangle(x11-1,y11-1,x22+1,y22+1);

			     }
			     else
			     {
				sound(100);
				delay(50);     //warning
				nosound();
			     }
			     break;

		case up :    if(y11>=258)
			     {
			     setcolor(BLACK);
			     rectangle(x11,y11,x22,y22);
				 rectangle(x11-1,y11-1,x22+1,y22+1);
			     y11-=60;
			     y22-=60;
			     setcolor(WHITE);
			     rectangle(x11,y11,x22,y22);
				 rectangle(x11-1,y11-1,x22+1,y22+1);
			     }
			     else
			     {
				sound(100);
				delay(50);
				nosound();
			     }
			     break;


		case right : if(x11<=560)
			     {
			     setcolor(BLACK);
			     rectangle(x11,y11,x22,y22);
				 rectangle(x11-1,y11-1,x22+1,y22+1);
				 x11+=60;
			     x22+=60;
			     setcolor(WHITE);
				 rectangle(x11,y11,x22,y22);
				 rectangle(x11-1,y11-1,x22+1,y22+1);
				 }
			     else
			     {
				sound(100);
				delay(50);
				nosound();
			     }
			     break;

		case left :  if(x11>=80)
			     {
			     setcolor(BLACK);
				 rectangle(x11,y11,x22,y22);
				 rectangle(x11-1,y11-1,x22+1,y22+1);
				 x11-=60;
			     x22-=60;
			     setcolor(WHITE);
			     rectangle(x11,y11,x22,y22);
				 rectangle(x11-1,y11-1,x22+1,y22+1);
			     }
			     else
			     {
				sound(100);
				delay(50);
				nosound();
			     }
			     break;

		case enter :
				ele=21;
				for(i=38,ele;i<=578,ele<=30;i+=60,ele++)
				{
					if(x11==i&&y11==198)
					    output(ele);
				}
				ele=39;
				for(i=38,ele;i<=578,ele<=48;i+=60,ele++)
				{
					if(x11==i&&y11==258)
					    output(ele);
				}
				ele=71;
				for(i=38,ele;i<=578,ele<=80;i+=60,ele++)
				{
					if(x11==i&&y11==318)
					    output(ele);
				}
				ele=103;
				for(i=38,ele;i<=578,ele<=112;i+=60,ele++)
				{
					if(x11==i&&y11==378)
					    output(ele);
				}
		case esc : start();
				   break;

		}
	}
	while(ch!=esc);      //loop till esc is pressed

	getch();
}

//---------------------------------------------------------------------------

void fblock()
{
	cleardevice();
	settextstyle(8,0,5);
	setcolor(YELLOW);
	outtextxy(230,50,"F-BLOCK");
	int n=0,i=0,ele;
	int x1=45,y1=270,x2=75,y2=300;
	int x11=15,y11=280;
	setcolor(WHITE);

	for(int j=0;j<14;j++)
	{
		for(n=0;n<2;n++)
		{
			if(j==0)
				setfillstyle(1,YELLOW);
			else
			{	setfillstyle(1,10);}
			bar(x1,y1+i,x2,y2+i);
			i+=80;
			delay(50);
		}
		x1+=40;
		x2+=40;
		y1=270;
		y2=300;
		i=0;
	}

	settextstyle(2,0,5);
	outtextxy(10,240,"-- LANTHANOIDS SERIES --");
	outtextxy(10,320,"-- ACTENOIDS SERIES --");

	setcolor(BLACK);
	char la[][15]={{"."},{"La"},{"Ce"},{"Pr"},{"Nd"},{"Pm"},{"Sm"},{"Eu"},{"Gd"},
		       {"Tb"},{"Dy"},{"Ho"},{"Er"},{"Tm"},{"Yb"}};
	char ac[][15]={{"."},{"Ac"},{"Th"},{"Pa"},{"U"},{"Np"},{"Pu"},{"Am"},{"Cm"},
		       {"Bk"},{"Cf"},{"Es"},{"Fm"},{"Md"},{"No"}};

	for(i=0;i<15;i++)
	{
		outtextxy(x11+=40,y11,&la[i][15]);
		delay(50);
	}
	y11+=80;
	x11=15;
	for(i=0;i<15;i++)
	{
		outtextxy(x11+=40,y11,&ac[i][15]);
		delay(50);
	}

	//nav box
	x11=43;
	y11=268;
	int x22=77,y22=302;
	setcolor(WHITE);
	rectangle(x11,y11,x22,y22);
	rectangle(x11-1,y11-1,x22+1,y22+1);
	char ch;
	do
	{                    // accepting ch in loop
		ch=getch();
		switch(ch)
		{
		case down :  if(y11<=320)//(last coordinate of y1) - 60 ~ appr
			     {
			     setcolor(BLACK);    //dissapearing before rect
			     rectangle(x11,y11,x22,y22);
			     rectangle(x11-1,y11-1,x22+1,y22+1);
			     y11+=80;
			     y22+=80;   //inc coord
			     setcolor(WHITE);
			     rectangle(x11,y11,x22,y22); //drawing new rect
			     rectangle(x11-1,y11-1,x22+1,y22+1);


			     }
			     else
			     {
				sound(100);
				delay(50);     //warning
				nosound();
			     }
			     break;

		case up :    if(y11>=338)
			     {
			     setcolor(BLACK);
			     rectangle(x11,y11,x22,y22);
				 rectangle(x11-1,y11-1,x22+1,y22+1);
			     y11-=80;
			     y22-=80;
			     setcolor(WHITE);
			     rectangle(x11,y11,x22,y22);
				 rectangle(x11-1,y11-1,x22+1,y22+1);
			     }
			     else
			     {
				sound(100);
				delay(50);
				nosound();
			     }
			     break;


		case right : if(x11<=560)
			     {
			     setcolor(BLACK);
			     rectangle(x11,y11,x22,y22);
				 rectangle(x11-1,y11-1,x22+1,y22+1);
				 x11+=40;
			     x22+=40;
			     setcolor(WHITE);
				 rectangle(x11,y11,x22,y22);
				 rectangle(x11-1,y11-1,x22+1,y22+1);
				 }
			     else
			     {
				sound(100);
				delay(50);
				nosound();
			     }
			     break;

		case left :  if(x11>=80)
			     {
			     setcolor(BLACK);
				 rectangle(x11,y11,x22,y22);
				 rectangle(x11-1,y11-1,x22+1,y22+1);
				 x11-=40;
			     x22-=40;
			     setcolor(WHITE);
			     rectangle(x11,y11,x22,y22);
				 rectangle(x11-1,y11-1,x22+1,y22+1);
			     }
			     else
			     {
				sound(100);
				delay(50);
				nosound();
			     }
			     break;

		case enter :
				ele=57;
				for(i=43,ele;i<=563,ele<=70;i+=40,ele++)
				{
					if(x11==i&&y11==268)
						output(ele);
				}
				ele=89;
				for(i=43,ele;i<=563,ele<=102;i+=40,ele++)
				{
					if(x11==i&&y11==348)
						output(ele);
				}
				
		case esc : start();
				   break;
				   
		}
	}
	while(ch!=esc);      //loop till esc is pressed
	getch();
}

//---------------------------------------------------------------------------

void main()
{
     //this is tested on borland turbo c++ only, im not sure about IDEs
	clrscr();
	int gd=DETECT; int gm;
	initgraph(&gd,&gm,"C:\\TC\\BGI");
	setfillstyle(0,GREEN);
	settextstyle(8,0,5);
	setcolor(GREEN);
	outtextxy(100,100,"THE PERIODIC TABLE");
	delay(1500);
	cleardevice();
	setcolor(WHITE);
	border();
	settextstyle(2,0,4);
	outtextxy(50,100,"INSTRUCTIONS : ");
	outtextxy(50,200,"1. You can navigate to S,P,D and F block by pressing S,P,D,F keys respectively.");
	outtextxy(50,300,"2. Press ESC to exit in any case.");
	getch();
	cleardevice();
	start();
}

//---------------------------------------------------------------------------


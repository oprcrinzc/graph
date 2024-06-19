#include<iostream>
#include<unistd.h>
using namespace std;
int main(){
	int width = 46;
	int height = 9;
	int r = 2;
	int vx = -width+r;
	int vy = height-r;
	int xind = 1;
	int yind = -1;
	int loop = 1;
	int st = r;
	do{
		if(vx>=width-r) xind = -1;
		else if(vx<=-width+r+1) xind = 1;
		if(vy>=height-r) yind = -1;
		else if(vy<=-height+r) yind = 1;
		for(int i=height;i>-height;i--){
			for(int j=-width;j<width;j++){
				//if(mul*j==i) cout << "1";
				//if(mul*mul >= j*j + i*i && mul*mul <= j*j + i*i) cout << mul;
				if(r*r == (j-vx)*(j-vx) + (i-vy)*(i-vy)) cout << "#";
				else cout << " ";
			}
			cout << "| ";
			if(i==height) {cout << " " << xind << " " << yind;}
			cout << endl;
		}
		vx += xind;
		vy += yind;
		usleep(50000);
		system("clear");
	} while(loop==1);
}

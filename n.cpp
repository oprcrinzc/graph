#include<iostream>
#include<vector>
//#include<algorithm>
#include<unistd.h>
using namespace std;
int main(){
	int width = 60;
	int height = 20;
	int r = 1;
	int vx = -width+r;
	int vy = height-r;
	int xind = 1;
	int yind = -1;
	int loop = 1;
	int max_mem = 25*1*10*10;
	vector<int> xline = {-width+r};
	vector<int> yline = {height-r};
	vector<int> _xline;
	vector<int> _yline;
	do{
		if(vx>=width-r) {xind = -1;}
		else if(vx<=-width+r+1) xind = 1;
		if(vy>=height-r) yind = -1;
		else if(vy<=-height+r) yind = 1;
		for(int i=height;i>-height;i--){
			for(int j=-width;j<width;j++){
				int l = 0;
				int b = 0;
				int k;
				int kk;
				//if(mul*j==i) cout << "1";
				//if(mul*mul >= j*j + i*i && mul*mul <= j*j + i*i) cout << mul;
				for( k=0;k < yline.size();k++){
					if(xline.at(k) == j &&  yline.at(k) == i){
						l = 1;
						break;
					}
				}
				if(xline.size()>max_mem) xline.clear();
				if(yline.size()>max_mem) yline.clear();
				if(r*r == (j-vx)*(j-vx) + (i-vy)*(i-vy)){
					cout << "#";
					xline.push_back(j);
					yline.push_back(i);
				}
				else if(l==1){
					cout << "#";
				}
				else cout << " ";
			}
			cout << "| ";
			if(i==height) cout << " " << xind << " " << yind;
			else if(i==height-1) cout << "x, y : " << vx << " " << vy;
			else if(i==height-2) cout << "xline, yline: " << xline.size() << " " << yline.size();
			cout << endl;
		}
		vx += xind;
		vy += yind;
		usleep(20000);
		system("clear");
	} while(loop==1);
}

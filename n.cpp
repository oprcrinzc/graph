#include<iostream>
#include<vector>
//#include<algorithm>
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
	vector<int> xline = {-width+r};
	vector<int> yline = {height-r};
	do{
		if(vx>=width-r) {xind = -1;}
		else if(vx<=-width+r+1) xind = 1;
		if(vy>=height-r) yind = -1;
		else if(vy<=-height+r) yind = 1;
		for(int i=height;i>-height;i--){
			for(int j=-width;j<width;j++){
				int l = 0;
				int b = 0;
				//if(mul*j==i) cout << "1";
				//if(mul*mul >= j*j + i*i && mul*mul <= j*j + i*i) cout << mul;
				for(int k=0;k < yline.size();k++){
					for(int kk=0;kk < xline.size();kk++){
						if(kk >= k){
						if(xline.at(kk) == j &&  yline.at(k) == i){
							l = 1;
							//xline.erase(kk);
							//yline.erase(k);
							break;
							b = 1;
						}}
					}
					if(b==1) break;
				}
				if(xline.size()>width*2) xline.clear();
				if(yline.size()>height*2) yline.clear();
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
		usleep(50000);
		system("clear");
	} while(loop==1);
}

#include<iostream>
#include<vector>
//#include<algorithm>
#include<unistd.h>
using namespace std;
int main(){
	int width=49, height=9, rfr=3;
	int x=-width, y=height;
	int ind_x=1, ind_y=-1;
	int max_mem = 20;
	vector<int> line_x, line_y;
	while(1==1){
		for(int py = height;py >= -height;py--){
			for(int px = -width;px <= width;px++){
				int isLine = 0;
				int last = 0;
				for(int i=0;i<line_x.size();i++){
					if(line_x.at(i)==px && line_y.at(i)==py) {
						isLine=1;
						if(line_x.at(0) == line_x.at(i)) last = 1;
					}
				}
				if(py == y && px == x){
					cout << "🐥";
					line_x.push_back(x);
					line_y.push_back(y);
				} else if(isLine==1) {
					if(last) cout << "🐥";
					else cout << "🥚";
					} 
				else cout << " ";
			}
			cout << "| " << py << endl;
		}
		if(line_x.size()>max_mem) line_x.erase(line_x.begin());
		if(line_y.size()>max_mem) line_y.erase(line_y.begin());
		x+=ind_x;
		y+=ind_y;
		if(x>=width) ind_x = -1;
		else if (x<=-width)ind_x = 1;
		if(y <= -height) ind_y = 1;
		else if(y>=height) ind_y = -1;
		usleep(rfr*10000);
		system("clear");
	}
}

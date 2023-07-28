#include <iostream>
#include <chrono>
#include <ctime>

using namespace std;

int main(){
	auto start = std::chrono::system_clock::now();
	auto end = std::chrono::system_clock::now();
	
    time_t date = chrono::system_clock::to_time_t(start);
	string dat = string(ctime(&date));
	
    string mon = dat.substr(4,3);
    string day;
	if (dat[8]==' ')
        day = dat.substr(9,1);
	else
        day = dat.substr(8,2);
    string yr = dat.substr(20,4);
    string fname = "c:\\Cornell Study\\" + mon + "_" + day + "_" + yr + ".txt";
    
	
	FILE * fid = fopen(fname.c_str(),"w");
	string inp;
	int sec=0;
	int cnt = 0;
	printf("Press q or Q to exit, press ' to pause or resume work\n");
	printf("Today is %s %s, %s!\n",mon.c_str(),day.c_str(),yr.c_str());
	fprintf(fid,"Today is %s %s, %s!\n",mon.c_str(),day.c_str(),yr.c_str());
	while(cin>>inp){
		if (inp[0]=='\''){
		if ((cnt%2==0) && (inp[0]!='q') && (inp[0]!='Q')){
		    start = std::chrono::system_clock::now();
			date = chrono::system_clock::to_time_t(start);
			dat = string(ctime(&date));
			if (cnt == 0){
				printf("Work starts at %s\n",dat.substr(11,8).c_str());
				fprintf(fid,"Work starts at %s\n",dat.substr(11,8).c_str());
			}
			else{
			    printf("Work resumes at %s\n",dat.substr(11,8).c_str());
				fprintf(fid,"Work resumes at %s\n",dat.substr(11,8).c_str());
			}
			cnt++;
		}
		else if (cnt%2==1){
			end = std::chrono::system_clock::now();
			date = chrono::system_clock::to_time_t(end);
			dat = string(ctime(&date));
			chrono::duration<double> elapsed_seconds = end-start;
			sec += int(elapsed_seconds.count());
			printf("Work paused at %s, and working time so far is \"%d hours, %d minutes, %d seconds\"\n",dat.substr(11,8).c_str(),sec/3600,(sec/60)%60,sec%60);
			fprintf(fid,"Work paused at %s, and working time so far is \"%d hours, %d minutes, %d seconds\"\n",dat.substr(11,8).c_str(),sec/3600,(sec/60)%60,sec%60);
			cnt++;
		}
		}
		if (inp[0]=='q'||inp[0]=='Q'){
            if (cnt%2==1){
			    end = std::chrono::system_clock::now();
			    chrono::duration<double> elapsed_seconds = end-start;
			    sec += int(elapsed_seconds.count());
            }
			printf("My total working hours is \"%d hours, %d minutes, %d seconds\"\n",sec/3600,(sec/60)%60,sec%60);
			fprintf(fid,"My total working hours is \"%d hours, %d minutes, %d seconds\"\n",sec/3600,(sec/60)%60,sec%60);
			break;
		}
	}
	
	
	
	fclose(fid);
	
    return 0;
}


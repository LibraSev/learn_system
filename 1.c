#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <sys/utsname.h>
#include <sys/sysinfo.h>
#include <linux/kernel.h> 
#include <errno.h>
#include <time.h> 
int main(){
	getcpu();
	release1();

	print_system_boot_time();
//	uptime();	
    CCUP();
    DCUP();
}

int release1(){
    struct utsname buf;
    if (uname(&buf) == -1)
         exit(1);    
    printf("release: %s\n", buf.release);

     return 0;
} 

int getcpu(){
	char all[10240];
	int n;
	FILE *fd;
	char *cpu;
	fd = fopen ("/proc/cpuinfo", "r");
	for(n=0;n<100;n++){
	fgets (all, sizeof(all), fd);
	cpu=strstr(all,"model name");
	if (cpu){
		printf("´¦ÀíÆ÷ÐÍºÅ");
		printf("%s",cpu);
	break;
	}		
	}		
} 

 int print_system_boot_time(){
     struct sysinfo info;
     time_t cur_time = 0;
     time_t boot_time = 0;
     struct tm *ptm = NULL;
     int day=0;
     if (sysinfo(&info)) {
     fprintf(stderr, "Failed to get sysinfo, errno:%u, reason:%s\n",errno, strerror(errno));
     return -1;
     }
     time(&cur_time);
     boot_time = info.uptime;
     ptm = gmtime(&boot_time);
    ptm->tm_mday--;
     printf("System boot time:  %d:%d:%d:%d\n",ptm->tm_mday,ptm->tm_hour, ptm->tm_min, ptm->tm_sec);
    return 0; 
 }
 
 int uptime(){
     struct sysinfo info;
     double t1;
	 t1=info.uptime;
     printf("%ld",t1);
 }
 
 
 int CCUP(){
 	char all[10240];
	int n;
	FILE *fd;
	char *a;
	fd = fopen ("/proc/stat", "r");
	
	//cpu
	for(n=0;n<100;n++){
		fgets (all, sizeof(all), fd);
		a=strstr(all,"cpu");
		if (a){
			printf("%s",a);
			break;
    	}	
    }
    //ctxt
    	for(n=0;n<100;n++){
		fgets (all, sizeof(all), fd);
		a=strstr(all,"ctxt");
		if (a){
			printf("%s",a);
			break;
    	}	
    }
    //btime
    	for(n=0;n<100;n++){
		fgets (all, sizeof(all), fd);
		a=strstr(all,"btime");
		if (a){
			printf("%s",a);
			break;
    	}	
    }    
    //process
    	for(n=0;n<100;n++){
		fgets (all, sizeof(all), fd);
		a=strstr(all,"process");
		if (a){
			printf("%s",a);
			break;
    	}	
    }     
 }
int DCUP(){
	char all[10240];
	int n;
	FILE *fd;
	char *a;
	fd = fopen ("/proc/meminfo", "r");
	//memtotal
	for(n=0;n<100;n++){
		fgets (all, sizeof(all), fd);
		a=strstr(all,"MemTotal");
		if (a){
			printf("%s",a);
			break;
    	}	
    }
    //MemFree
	for(n=0;n<100;n++){
		fgets (all, sizeof(all), fd);
		a=strstr(all,"MemFree");
		if (a){
			printf("%s",a);
			break;
    	}	
    }
    
    
    
    
    
    
    
    
}    
    
    
    


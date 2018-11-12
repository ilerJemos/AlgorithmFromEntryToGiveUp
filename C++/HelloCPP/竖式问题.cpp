//竖式问题
//找出所有形如abc*de的算式，使得在完整的竖式中，所有数字都属于一个特定的数字集合 
 #include<stdio.h>
 #include<string.h>
 int mai33n(){
 	int count=0;
 	char s[20],buf[99];
 	//scanf("%s",s);//字符串不需要加“&” 
     s[0]='a';
// 	printf("%d %c %s",strlen(s),s[0],s);
 	for(int abc = 111;abc<=999;abc++){
 		for(int de=11;de<=99;de++){
 			int x= abc*(de%10),y =  abc*(de/10),z=abc*de;
 			sprintf(buf,"%d%d%d%d%d",abc,de,x,y,z);
 			int ok = 1;
 			for(int i=0;i<strlen(buf);i++){
 				if(strchr(s,buf[i])==NULL) 
					ok=0;
				}
 			if(ok){
 				printf("<%d>\n",++count);
 				printf("%5d\nX%4d\n-----\n%5d\n%4d\n-----\n%5d\n\n",abc,de,x,y,z);
			 }
		 }
	 }
	printf("The number of solutions = %d\n",count);
 	return 0;
 } 
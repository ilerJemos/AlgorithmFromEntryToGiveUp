#include<stdio.h>

 int main(){
     int l,j,k;
     int t[10];
     int  a,b,c,d,e,f,g,h,i;
     for( i= 0;i<10;i++){
            t[i]=0;
        }
    for(  a = 1;a<=9;a++){
        
        t[a] = 1;
        for(  b = 1;b<=9;b++){
            if(t[b]==1) continue;
            t[b]=1;
            for(  c = 1; c<=9;c++){
                if(t[c]==1) continue;
                t[c]=1;
                for(  d = 1; d<=9;d++){
                    if(t[d]==1) continue;
                    t[d]=1;
                    for(  e = 1; e<=9;e++){
                        if(t[e]==1) continue;
                        t[e]=1;
                        for(  f = 1; f<=9;f++){
                            if(t[f]==1) continue;
                            t[f]=1;
               
                            for(  g = 1; g<=9;g++){
                                if(t[g]==1) continue;
                                t[g]=1;
                
                                for(  h = 1;h<=9;h++){
                                    if(t[h]==1) continue;
                                    t[h]=1;
                
                                    for(  i = 1; i<=9;i++){
                                        if(t[i]==1) continue;
                                        l = a*100+b*10+c;
                                        j = d*100+e*10+f;
                                        k = g*100+h*10+i;
                                        //printf("%d %d %d\n",l,j,k);
                                        if( j/l ==2 &&  j% l==0&&k/ l == 3&&k% l ==0)
                                        printf("%d %d %d\n", l, j,k);
                    
                                    }
                                    t[h]=0;

                                 }
                                t[g]=0;

                            }
                            t[f]=0;

                        }
                        t[e]=0;
                    }
                    t[d]=0;

                    }
                t[c]=0;

            }
            t[b]=0;
        }
        t[a]=0;
    }
    return 0;
}
class Robot {
public:
    int rows,cols;
    string dir;
    int x,y;
    int total;
    Robot(int width, int height) {
        rows=height;
        cols=width;
        x=0;y=0;
        dir="East";
        total=width*2+(height-2)*2;
    }
    
    void step(int num) {
        //robot walks only corner rows and cols
        num=num%total;
        if(x==0 && y==0  && num==0)
            dir="South";
        int steps;
        while(num!=0)
        {
            if(dir=="East")
            {
                
                //increase the x
                steps=min(cols-(x+1),num);
                num-=steps;
               
                if(num)
                {
                    dir="North";
                }
                x+=steps;
            }
            else if(dir=="North")
            {
                
                steps=min(rows-(y+1),num);
                num-=steps;
              
                if(num)
                    dir="West";
                y+=steps;
            }
            else if(dir=="West")
            {
                steps=min(x,num);
                num-=steps;
                
                if(num)
                {
                    dir="South";
                }
                x-=steps;
            }
            else if(dir=="South")
            {
                steps=min(y,num);
                num-=steps;
              
                if(num)
                    dir="East";
                y-=steps;
            }
            
            
        }
    }
    
    vector<int> getPos() {
        return {x,y};
    }
    
    string getDir() {
        return  dir;
    }
};

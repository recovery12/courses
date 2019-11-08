///
//
//Search Vizualizer
//
//HACKWEEK PROJECT
//
//renjith p ravindran 2017 
//rprx
//------------------------------


var canvas_dim={w:400,h:400};
var grid_dim={w:0,w:0};
var cell_dim={w:0,h:0};


init_cell={i:0,j:0};
final_cell={i:0,j:0};

var grid = new Array();


//-----colors
var canvas_bg=200;
var open_cell={r:230,g:255,b:230};
var closed_cell={r:100,g:0,b:0};
var visisted_cell={r:150,g:150,b:150};
var path_cell={r:0,g:153,b:51}
var init_final_cell={r:0,g:0,b:0};
//------solver---
var visited_states= new Array();
var meta=  buckets.Dictionary();
var goal_path=new Array();
var visit_head=0;
//-----swithes
var draw_grid_switch=true;
var show_solution_switch=false;





var prev_mouse_cell={i:-1,j:-1};

function setup(){
    
    var canvas=createCanvas(canvas_dim.w+2,canvas_dim.w+2);
    background(canvas_bg);

    set_grid(); 
    fri=fringe("bfs");
    fri.push(1);
    ////console.log(fri.pop());
    }



function draw(){
    
    draw_grid();
    //draw_cell_visits();
    
    var visit={i:0,j:0};
    if (show_solution_switch){
    if(visit_head<visited_states.length){
        visit.i=visited_states[visit_head].i;
        visit.j=visited_states[visit_head].j;
        ////console.log("visit") ;
        draw_cell(visit.i,visit.j,2);
        visit_head++;
        ////console.log(visit_head);
    }
    else{
        show_solution_switch=false;
        draw_path()
        }
}

}

function set_grid(){
    
    grid_dim.w=document.getElementById("grid_w").value;
    grid_dim.h=grid_dim.w;
    
    final_cell={i:grid_dim.w-1,j:grid_dim.h-1};
    cell_dim.w=canvas_dim.w/grid_dim.w;
    cell_dim.h=canvas_dim.h/grid_dim.w;

   
    for (var i=0; i<grid_dim.w; i++){
        
        grid[i]= new Array();
        for (var j=0; j<grid_dim.h;j++){
            
            grid[i][j]=0;

            }
        }
    draw_grid_switch=true;
    }

function draw_cell(cell_i,cell_j,type){
    if((cell_i==init_cell.i && cell_j==init_cell.j) || (cell_i==final_cell.i && cell_j==final_cell.j))
        fill(init_final_cell.r,init_final_cell.g,init_final_cell.b);
    else if (type==0)
        fill(open_cell.r,open_cell.g,open_cell.b);
    else if (type==1)
        fill(closed_cell.r,closed_cell.g,closed_cell.b);
    else if (type==2){
        ////console.log("2");
        fill(visisted_cell.r,visisted_cell.g,visisted_cell.b);
    }
    else if(type==3){

        fill(path_cell.r,path_cell.g,path_cell.b);
        }

    rect(cell_i*cell_dim.w,cell_j*cell_dim.h,cell_dim.w,cell_dim.h);

       
    }


function draw_grid(){
    
    if (!draw_grid_switch)
        return;
    draw_grid_switch=false;
    
    for (var i=0; i<grid_dim.w;i++){
        for (var j=0;j<grid_dim.h;j++){
            draw_cell(i,j,grid[i][j]);
            if(i==init_cell.i && j==init_cell.j){
        //console.log("!!!");
        fill(0, 102, 153);
        textSize(32);
        text("I", 100, 100);
        }
            }
        }
    }


function draw_path(){
    
    var cell={};
        //console.log("****");
    for(var g =0 ; g<goal_path.length;g++){
        //console.log("%%%");
        cell=goal_path[g];
       //console.log(cell);
        draw_cell(cell.i,cell.j,3);
        
        }
    
    
    }


function mouseClicked(){
    mark_grid();
    
    }
function mouseDragged(){
    mark_grid();
    
    }
function mouseReleased(){
    prev_mouse_cell={i:-1,j:-1};
    
    }

function mark_grid(){

    if (show_solution_switch)
        return

    for (var i=0;i<grid_dim.w;i++){
        for (var j=0;j<grid_dim.h;j++){
            if(mouseX>=(i*cell_dim.w) && mouseX<=(i+1)*cell_dim.w){
                if (mouseY>=(j*cell_dim.h) && mouseY<=(j+1)*cell_dim.h){

                    if((i==init_cell.i && j==init_cell.j)||(i==final_cell.i && j==final_cell.j))
                        return;

                    if (prev_mouse_cell.i==i && prev_mouse_cell.j==j)
                        return;

                    if (grid[i][j]==0){
                        grid[i][j]=1;
                    }
                    else{
                        grid[i][j]=0;
                    }
                    draw_cell(i,j,grid[i][j]);
                    prev_mouse_cell={i:i,j:j};
                    return;
            }
        }
    
    }
    }
    
    }

function fringe(algo){
    
    if (algo=='dfs'){
        fr={}
        fr=buckets.Stack();
        fr.push=fr.push;
        fr.pop=fr.pop;
        
        }
     else if (algo=='bfs'){
        fr={}
        fr=buckets.Queue();
        fr.push=fr.enqueue;
        fr.pop=fr.dequeue;
         
         
         }
     else if (algo=='astar'){
        fr={}
        fr=buckets.PriorityQueue(state_priority);
        fr.push=fr.enqueue;
        fr.pop=fr.dequeue;
         
         
         }
        return fr;
    }

function solve(){
    
    var algo=document.getElementById("algo").value;
    ////console.log(algo);    
    var move=document.getElementById("move").value;
        
    if (move=='4')
    vectors=[[0,1],[0,-1],[1,0],[-1,0]];
    else
    vectors=[[0,1],[0,-1],[1,0],[-1,0],[1,1],[-1,-1],[1,-1],[-1,1]];
    meta=buckets.Dictionary();
    if (algo=="astar")
    visited_states=search_astar(algo);
    else
    visited_states=search(algo);
    visit_head=0;
    draw_grid_switch=true;
    show_solution_switch=true;
    goal_path= new Array();
    get_goal_path();
    //console.log(goal_path);

    
    }

function state_comparator(s1,s2){
    
    if (s1.i==s2.i && s1.j==s2.j)
        return true;
    else
        return false;
    
    }

function search(algo){
    
    var open_states=fringe(algo);
    open_states.push(init_cell);

    var closed_states=buckets.LinkedList();

    var success=false;
    var ii=0
    var open_states_size=0;
    while(!open_states.isEmpty()){
        ii++;
        //console.log(ii);
        //console.log(closed_states.size());
        
        var current_state=open_states.pop();
        //console.log(current_state);
        //console.log(strit(closed_states.toArray()));
        //console.log(strit(open_states.toArray()));
        if (is_goal_state(current_state)){
            success=true;
            closed_states.add(current_state)
            ////console.log("@");
            break;
            }
        else{
            
                closed_states.add(current_state)

           var next_states=get_next_states(current_state);

            ////console.log(next_states.size());
           for (var i=0;i<next_states.size();i++){
               var next_state=next_states.toArray()[i];
            ////console.log(next_state);

               if (closed_states.contains(next_state,state_comparator))
                        continue;

                    if (open_states.contains(next_state,state_comparator)==false){
                        meta.set(strit({i:next_state.i,j:next_state.j}),{i:current_state.i,j:current_state.j});
                        open_states.push(next_state);
                        }
                    }
                
            }
        
        }
    if(success){
       //console.log("$$");
       //console.log(closed_states.size());
        return closed_states.toArray();
        }
    else{
        ////console.log("$");
        return closed_states.toArray();
        }

        

    
    
    }


function get_goal_path(){
   
    var state=final_cell;
    var action='';
    goal_path.push(init_cell);
    while (strit(state)!=strit(init_cell)){

        action=meta.get(strit(state));
        goal_path.push(state);
        state=action;
        


}}





function is_open_cell(cell){

    if (cell.i>=0 && cell.i<grid_dim.w){
        if (cell.j>=0 && cell.j<grid_dim.h){
            if (grid[cell.i][cell.j] ==0)
                                        {
                return true;
                                        }
        }
    }
    return false;

    
    
    }


function get_next_states(cell){
   

    var next_cells= buckets.LinkedList()
    var new_cell={i:0,j:0};

    for (i in vectors){
        new_cell.i=cell.i+vectors[i][0];
        new_cell.j=cell.j+vectors[i][1];
        ////console.log(new_cell);
        if (is_open_cell(new_cell) ){
            next_cells.add({i:new_cell.i,j:new_cell.j,g:0,f:0});
        }
    }
    return next_cells;
 


    }

function is_goal_state(state){
    
    if (state.i==final_cell.i && state.j==final_cell.j)
        return true
    else
        return false;
    
    }
    
    
function strit(item){
    return JSON.stringify(item);
}



function state_priority(s1,s2){
    
    if ((s1.f)>(s2.f))
        return 1;
    else if ((s1.f)<(s2.f))
        return -1;
    else
        return 0;
    
    }

function hueristic(s){
    
    var value=0;
    if (move=='4')
        value=(final_cell.i-s.i) + (final_cell.j-s.j);
    else (move=='8')
        value=Math.sqrt(Math.pow((final_cell.i-s.i),2) + Math.pow(final_cell.j-s.j,2));

        return value;
    
    }


function search_astar(algo){
    
    var open_states=fringe(algo);
    open_states.push({i:init_cell.i,j:init_cell.j,g:0,f:1/hueristic(init_cell)});

    var closed_states=buckets.LinkedList();

    var success=false;
    var ii=0
    var open_states_size=0;
    while(!open_states.isEmpty()){
        ii++;
       //console.log("ii:"+ii.toString());
       //console.log("closed size");
       //console.log(closed_states.size());
        var current_state=open_states.pop();
       //console.log(current_state);
        //console.log(strit(closed_states.toArray()));
        //console.log(strit(open_states.toArray()));
        if (is_goal_state(current_state)){
            success=true;
            closed_states.add(current_state)
            ////console.log("@");
            break;
            }
        else{
            
           if (closed_states.contains(current_state,state_comparator)==false)
                closed_states.add(current_state)

           var next_states=get_next_states(current_state);
           
           //console.log("next state");
           //console.log(next_states.toArray());
           for (var i=0;i<next_states.size();i++){
               var next_state=next_states.toArray()[i];
             // //console.log("next");
            //console.log(strit(next_state));

               if (closed_states.contains(next_state,state_comparator)){
                      //console.log("cont")
                       continue;

               }
                



              //         //console.log(open_states.contains(next_state,state_comparator))
                    if (open_states.contains(next_state,state_comparator)==false){
                        next_state.g=current_state.g+1;
                        next_state.f=next_state.g + hueristic(next_state)
                        next_state.f=1/next_state.f;
                        meta.set(strit({i:next_state.i,j:next_state.j}),{i:current_state.i,j:current_state.j});
                        open_states.push(next_state);
           //console.log(strit(next_state));
                       //console.log("added");
                        }
                        else{
                           //console.log("not added");
                           //console.log(next_state);
                            }
                    }
                
            }
        
        }
    if(success){
       //console.log("$$");
       //console.log(closed_states.size());
        return closed_states.toArray();
        }
    else{
       //console.log("$");
        return closed_states.toArray();
        }

        

    
    
    }

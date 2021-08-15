// Union Find: https://leetcode.com/problems/last-day-where-you-can-still-cross/discuss/1403988/Python-3-Union-Find-join-the-water-not-the-land-explanation-with-pictures.
// Binary Search: https://leetcode.com/problems/last-day-where-you-can-still-cross/discuss/1403907/C%2B%2BJavaPython-Binary-Search-and-BFS-Clean-and-Concise
class Node {
    public:
    int start = INT_MAX;
    int end = INT_MIN;
     
    Node(int row, int col) {
        start = min(start, col);
        end  = max(end, col);
    }
  
};

class Solution {
public:
    int dx[8] = { 0, 1, 1, 1, 0, -1, -1, -1 };
    int dy[8] = { 1, 1, 0, -1, -1, -1, 0, 1 };
    unordered_map<Node*, Node*> parent;
    
    Node* getParent(Node* fu, Node* child) {
        if( !parent.count(fu) ) {
            if( child )  {
                fu->start = min(fu->start, child->start);
                fu->end = max(fu->end, child->end);
            }
            return fu; 
        }
        
        if( child )  {
            fu->start = min(fu->start, child->start);
            fu->end = max(fu->end, child->end);
        }
        
        Node* p = getParent(parent[fu], fu);
        parent[fu] = p ;
        return p ;
    }
    
    bool isBlocking(Node* fu, int row, int col) {
        Node* p = getParent(fu, NULL);
        if( p->start == 0 && p->end == col-1 ) return true;
        return false;
    }
    
    int latestDayToCross(int row, int col, vector<vector<int>>& cells) {
        
        map< pair<int,int>, Node*> mp;
        
        for( int cell = 0; cell < cells.size(); cell++) {
            vector<int>& ce = cells[cell];
            int r = ce[0]-1, c = ce[1]-1;
            
            Node* fu = new Node(r, c);
            
            for( int i = 0; i < 8; i ++) {
                int x = r + dx[i], y = c + dy[i];
                if( mp.count({ x, y }) ) {
                        Node* p1 = getParent(fu, NULL);
                        Node* p2 = getParent(mp[{x,y}], NULL);
                        if( p1 != p2 ) 
                            parent[p1] = p2;
                }
            }
            
            mp[{r,c}] = fu;
            
            if( isBlocking(fu, row, col) ) {
                return cell;
            }
        }
        
        return -1;
    }
};

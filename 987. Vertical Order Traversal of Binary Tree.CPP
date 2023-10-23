class Solution {

class Point {    
public:   
    TreeNode* Node;
    int x, y;

public:
    Point(TreeNode* Node, int x, int y) {
        
        this -> Node = Node;
        this -> x    = x;
        this -> y    = y;
    }  
};

    
class comparator {  
public:
     bool operator()(Point* a, Point* b) {
         
         return a -> y == b -> y ? (a -> Node -> val > b -> Node -> val) : (a -> y > b -> y);
     }      
};

public:
    vector<vector<int>> verticalTraversal(TreeNode* root) {
        
        queue<Point*> Queue;
        map<int, priority_queue<Point*, vector<Point*>, comparator>> Map;
        vector<vector<int>> vertical_traversal;
        
        
        int left_boundary = 0, right_boundary = 0;
        
        Queue.push(new Point(root, 0, 0));
    
        while(!Queue.empty())
        {
            Point* point = Queue.front(); Queue.pop();
            
            TreeNode* Node = point -> Node;
            int x = point -> x, y = point -> y;
            
            Map[x].push(point);
            
            left_boundary = min(left_boundary, x);
            right_boundary = max(right_boundary, y);
            
            if(Node -> left != nullptr)
                Queue.push(new Point(Node -> left, x - 1, y + 1));
            
            if(Node -> right != nullptr)
                Queue.push(new Point(Node -> right, x + 1, y + 1));
        }
        
        for(int i = left_boundary; i <= right_boundary; i++)
        {
            priority_queue<Point*, vector<Point*>, comparator> q = Map[i];
            vector<int> list;
            
            while(!q.empty()) 
            {    
                Point* point = q.top(); q.pop();
                list.push_back(point -> Node -> val);
            }
            
            if(!list.empty())
                vertical_traversal.push_back(list);
        }
            
        return vertical_traversal;
    }
};
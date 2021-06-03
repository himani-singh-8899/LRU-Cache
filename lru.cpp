struct Node 
{
        int data ; 
         Node * left , *right ;
         Node ( int data )
         {
             this -> data = data ; 
             left = right = NULL ; 
         }
};

class LRUCache {
public:
    
    
    int capacity ;
    int currentsize ; 
    Node * head , *last ; 
    map < int , Node * > mp ; 
    LRUCache(int capacity) {
        
        this -> capacity = capacity ; 
        currentsize = 0 ; 
        head = NULL ; 
        last = NULL ; 
        
        
    }
    
    int get(int key) {
        
        if (mp.find ( key ) == mp.end() or mp [ key ] -> data  == -1  )
                return -1 ; 
        Node * temp = mp [ key ] ; 
        update ( key , temp -> data ) ;  
        return mp [ key ] -> data ; 
    }
    
    void update ( int key , int value )
    {
        Node * temp = mp [ key ] ;
        temp -> data = value ; 
        if ( temp == head )
                    return ; 
        if ( temp == last )
            last = last -> left ; 
        if ( temp -> right ) 
                temp -> right -> left = temp -> left ; 
        if ( temp -> left )
                temp -> left -> right = temp -> right ; 
        head -> left = temp ; 
        temp -> right = head ; 
        head = temp ; 
        
    }
    
    
    void Delete ( )
    {
        Node * temp = last ; 
        temp -> data = -1 ; 
        last = last -> left ; 
        if ( last == NULL )
                head = NULL ; 
        if ( last )
            last -> right = NULL ; 
    }
    void put(int key, int value)
     {
                
        
        if ( mp.find( key ) != mp.end() and mp [ key ] -> data != -1     )
        {
            update ( key , value ); 
            return ; 
        }
        
        if ( currentsize == capacity )
        {
            Delete () ; 
            currentsize -- ; 
        }
        
        currentsize ++ ; 
        Node * ptr = new Node ( value ) ; 
        mp [ key ] = ptr ; 
        
        if ( !head )
        {
            head = ptr ; 
            last = ptr ; 
        }
        else 
        {
            head -> left = ptr ; 
            ptr -> right = head ; 
            head = ptr ; 
        }
        
        
    }
};

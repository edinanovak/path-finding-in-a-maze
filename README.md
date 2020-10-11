# path-finding-in-a-maze
Read a maze from a text file and find the path from start to end.

#-wall
x-unmark path
.-good path

Algorithm for path finding:

FindPath function:
1. if(x,y,outside maze) return FALSE;
2. if(x,y is goal) return TRUE;
3. if(x,y,not open) return FALSE;
4. mark (x,y) as part of solution path;
5. if(north) return TRUE;
6. if(east) return TRUE;
7. if(south) return TRUE;
8. if(west) return TRUE;
9. if (x,y)=='x' than unmark the path
10. return FALSE;

Using algorithm:

1. Locate the start and end position (is,js)
2. Call find_path(is,js)
3. Re-mark the start and end position with S and E at the end after found path.

import java.util.ArrayList;
import java.util.PriorityQueue;

class Solution{
    public static void main(String args[]){
        int events[][] = {{3, 4}, {2, 3}, {1, 2}};
        System.err.println(solve( events ));
    }

    public static int solve(int[][] events){
        ArrayList<Integer>[] vec = new ArrayList[10005];

        //Fill array
        //Arrays.setAll(vec, e -> new ArrayList<>());

        for (int i = 0; i < events.length; i++) {
            if( vec[i] ==null ){
                vec[i] = new ArrayList<>();
            }
            vec[i].add(events[i][1]);
        }

        PriorityQueue<Integer> pq = new PriorityQueue<>((a,b) -> b-a);

        int total = 0;
        for (int i = 1; i < 10005; i++) {
            if( !vec[i].isEmpty() ){
                for (int j = 0; j < vec[i].size(); j++) {
                    pq.add(vec[i].get(j));
                    total++;
                }
                pq.poll();
            }else{
                if( !pq.isEmpty() ){
                    if( pq.peek() <= i ){
                        pq.poll();
                        total++;
                    }else{
                        break;
                    }
                }
            }
        }

        return total;
    }
}
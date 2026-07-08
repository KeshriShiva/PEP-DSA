import java.io.*;
import java.util.*;

public class concerttickets {
    public static void main(String[] args) throws Exception {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        String[] nm = br.readLine().split(" ");
        int n = Integer.parseInt(nm[0]), m = Integer.parseInt(nm[1]);

        TreeMap<Integer, Integer> map = new TreeMap<>();
        String[] h = br.readLine().split(" ");
        for (int i = 0; i < n; i++) {
            int x = Integer.parseInt(h[i]);
            map.put(x, map.getOrDefault(x, 0) + 1);
        }

        String[] t = br.readLine().split(" ");
        StringBuilder sb = new StringBuilder();

        for (int i = 0; i < m; i++) {
            int x = Integer.parseInt(t[i]);
            Integer k = map.floorKey(x);
            if (k == null) sb.append("-1\n");
            else {
                sb.append(k).append("\n");
                if (map.get(k) == 1) map.remove(k);
                else map.put(k, map.get(k) - 1);
            }
        }

        System.out.print(sb);
    }
}

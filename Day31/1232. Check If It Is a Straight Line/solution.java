class Solution {
    public boolean checkStraightLine(int[][] coordinates) {
        int n = coordinates.length;
        int x1 = coordinates[0][0], x2 = coordinates[1][0],
        y1 = coordinates[0][1], y2 = coordinates[1][1];

        int dx = (x2-x1), dy = (y2-y1);

        for(int i=0; i<n; i++){
            if(dy * (coordinates[i][0] - x2) != dx * (coordinates[i][1] - y2)) return false;
        }
        return true;
    }
}

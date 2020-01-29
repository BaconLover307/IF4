import java.util.*;
import java.awt.*;
import javax.swing.JPanel;
import javax.swing.JFrame;
import javax.swing.SwingUtilities;;

public class ConvexHull {
    
    // $ Plotting
    private static void createPlot(PlotMap plot) {
        plot.setPreferredSize(new Dimension(600, 600));
        JFrame frame = new JFrame("Convex Hull");
        frame.setDefaultCloseOperation(JFrame.EXIT_ON_CLOSE);
        frame.getContentPane().add(plot);
        frame.pack();
        frame.setLocationRelativeTo(null);
        frame.setVisible(true);
    }
    
    // $ Tentukan Sisi
    public static int checkNodeSide(Node A, Node B, Node check) {
        return (check.x - A.x) * (B.y - A.y) - (check.y - A.y) * (B.x - A.x); 
    }
    
    public static Boolean searchNode(int x, int y, int total, Node arrNode[]) {
        Boolean found = false;
        int i = 0;
        while (!found && i<total-1) {
            if (x == arrNode[i].x && y == arrNode[i].y) {
                found = true;
            }
            i++;
        }
        return found;
    } 

    // $ Main
    public static void main(String[] args) {
        // $ Vars
        int nodes;
        int maxRand = 101;
        Scanner scNode = new Scanner(System.in);
        Random random = new Random();
        long startTime, stopTime;
        double durasi;
        
        // $ Code
        // * Read amount of nodes
        System.out.println("[ CONVEX HULL GENERATOR ]");
        System.out.printf("Silakan masukan jumlah node: ");
        nodes = scNode.nextInt();
        System.out.println();
        
        // * Generate array of random nodes
        System.out.println("Nodes:");
        Node arrNode[] = new Node[nodes];
        for (int i = 0; i < nodes; i++) {
            int randX = random.nextInt(maxRand);
            int randY = random.nextInt(maxRand);
            Boolean duplicate = searchNode(randX, randY, i, arrNode);
            while (duplicate) {
                randX = random.nextInt(maxRand);
                randY = random.nextInt(maxRand);
                duplicate = searchNode(randX, randY, i, arrNode);
            }
            arrNode[i] = new Node(randX, randY);
            System.out.println("(" + randX + "," + randY + ")");
        }
        System.out.println();
        
        // $ Make Convex Hull
        ArrayList<Line> listLine = new ArrayList<Line>();
        startTime = System.nanoTime(); // $ ### START TIME ###
        for (int i = 0; i<nodes; i++) {
            for (int j = 0; j<nodes; j++) {
                if (j == i) {
                    continue;
                }
                boolean pointOneSide = true;
                for (int k = 0; k<nodes; k++) {
                    if ((k == i) || (k == j)) {
                        continue;
                    }
                    int d = checkNodeSide(arrNode[i], arrNode[j], arrNode[k]);
                    if (d<0) {
                        pointOneSide = false;
                        break;
                    }
                }
                if (pointOneSide) {
                    listLine.add(new Line(arrNode[i],arrNode[j]));
                } 
            }
        }
        stopTime = System.nanoTime(); // $ ### STOP TIME ###
        durasi = (double) (stopTime-startTime) / 1000000;
        System.out.println("Waktu perhitungan : " + durasi + " ms");
        
        // * Draw Convex Hull
        PlotMap plot = new PlotMap(listLine, arrNode);
        plot.listConvexHull(plot);
        SwingUtilities.invokeLater(new Runnable() {
            public void run(){
                createPlot(plot);
            }
        });
    }
}

class Node {
    int x, y;
    Node(int x, int y) {
        this.x = x;
        this.y = y;
    }
}

class Line {
    Node nodeA, nodeB;
    ArrayList<Line> listLine;
    Line(Node nodeA, Node nodeB) {
        this.nodeA = nodeA;
        this.nodeB = nodeB;
    } 
    public int getNextIdx(ArrayList<Line> listLine) {
        int next = 0;
        boolean found = false;
        int x1 = this.nodeB.x;
        int y1 = this.nodeB.y;
        while (!found) {
            int x2 = listLine.get(next).nodeA.x;
            int y2 = listLine.get(next).nodeA.y;
            if (x1 == x2 && y1 == y2) {
                found = true;
            } else {
                next++;
            }
        }
        return next;
    }
    public int farthestPointIdx(ArrayList<Line> listLine, int idx) {
        double far, currDist;
        int farIdx;
        Node nA = this.nodeA;
        Node nB = this.nodeB;
        far = Math.sqrt((nB.x - nA.x)*(nB.x - nA.x) + (nB.y - nA.y)*(nB.y - nA.y));
        farIdx = idx;
        if (nB.x == listLine.get(0).nodeA.x && nB.y == listLine.get(0).nodeA.y) {
            return idx;
        } else {
            idx++;
            while (idx < listLine.size() && (nA.x == listLine.get(idx).nodeA.x && nA.y == listLine.get(idx).nodeA.y)) {
                Node nA2 = listLine.get(idx).nodeA;
                Node nB2 = listLine.get(idx).nodeB;
                    currDist = Math.sqrt((nB2.x - nA2.x)*(nB2.x - nA2.x) + (nB2.y - nA2.y)*(nB2.y - nA2.y));
                    if (far < currDist) {
                        farIdx = idx;
                        far = currDist;
                    }
                idx++;
            }
            return farIdx;
        }
    }
}

class PlotMap extends JPanel {
    // $ Constructor
    public ArrayList<Line> hull;
    public Node[] fill;

    public PlotMap(ArrayList<Line> hull, Node[] fill) {
        this.hull = hull;
        this.fill = fill;
    }
    
    public void listConvexHull(PlotMap plot) {
        System.out.println("Convex Hull:");
        System.out.printf("[");
        int idx = 0;
        do {
            System.out.printf("(" + hull.get(idx).nodeA.x + "," + hull.get(idx).nodeA.y +"),");
            if (idx < hull.size()-1) {
                idx = hull.get(idx).farthestPointIdx(hull,idx);
            }
            idx = hull.get(idx).getNextIdx(hull);
        } while (idx != 0);
        System.out.println("(" + hull.get(idx).nodeA.x + "," + hull.get(idx).nodeA.y +")]");
    }
    
    // $ Chart
    public static int scale = 100;
    private int padding = 20;
    private int labelPadding = 12;
    private Color lineColor = new Color(222, 80, 200);
    private Color pointColor = new Color(145, 14, 176);
    private Color gridColor = new Color(200, 200, 200, 200);
    private static final Stroke GRAPH_STROKE = new BasicStroke(2f);
    private static int pointWidth = 7;
    private int numberDivisions = 10;

    @Override
    protected void paintComponent(Graphics g) {
        super.paintComponent(g);
        Graphics2D g2 =  (Graphics2D) g;
        g2.setRenderingHint(RenderingHints.KEY_ANTIALIASING, RenderingHints.VALUE_ANTIALIAS_ON);
        FontMetrics metrics = g2.getFontMetrics();

        // * Chart Scale
        double xScale = (double) (getWidth() - (2 * padding) - labelPadding) / scale;
        double yScale = (double) (getHeight() - (2 * padding) -labelPadding) / scale;

        // * Tidy up data
        ArrayList<Node> fillPoints = new ArrayList<Node>();
        for (int i = 0; i < hull.size(); i++) {
            int x1 = (int) (hull.get(i).nodeA.x * xScale + padding + labelPadding);
            int y1 = (int) (getHeight() - (hull.get(i).nodeA.y * yScale + padding + labelPadding));
            int x2 = (int) (hull.get(i).nodeB.x * xScale + padding + labelPadding);
            int y2 = (int) (getHeight() - (hull.get(i).nodeB.y * yScale + padding + labelPadding));
            hull.set(i, new Line(new Node(x1,y1), new Node(x2,y2)));
        }
        for (int i = 0; i < fill.length; i++) {
            int x = (int) (fill[i].x * xScale + padding + labelPadding);
            int y = (int) (getHeight() - (fill[i].y * yScale + padding + labelPadding));
            fillPoints.add(new Node(x,y));
        }

        // * Chart Background
        g2.setColor(Color.WHITE);
        g2.fillRect(padding + labelPadding, padding,
                    getWidth() - 2*padding - labelPadding, getHeight() - 2*padding - labelPadding);

        // * Chart
        for (int i = 0; i < numberDivisions + 1; i++) {
            // * Horizontal Lines
            int xh0 = padding + labelPadding;
            int xh1 = pointWidth + padding + labelPadding;
            int yh0 = getHeight() - ((i * (getHeight() - padding * 2 -
            		labelPadding)) / numberDivisions + padding + labelPadding);
            int yh1 = yh0;
            g2.setColor(gridColor);
            g2.drawLine(padding + labelPadding + 1 + pointWidth, yh0, getWidth() - padding, yh1);
            g2.setColor(Color.BLACK);
            g2.drawLine(xh0, yh0, xh1, yh1);
            
            // * Vertical Lines
            int xv0 = i * (getWidth() - padding * 2 - labelPadding) / numberDivisions + padding + labelPadding;
            int xv1 = xv0;
            int yv0 = getHeight() - padding - labelPadding;
            int yv1 = yv0 - pointWidth;
            g2.setColor(gridColor);
            g2.drawLine(xv0, labelPadding + 1 + pointWidth, xv1, getHeight() -2* padding);
            g2.setColor(Color.BLACK);
            g2.drawLine(xv0, yv0, xv1, yv1);

            // * Label
            String Label = ((int) (scale / numberDivisions * i)) + "";
            int labelWidth = metrics.stringWidth(Label);
            g2.drawString(Label, xh0 - labelWidth - 6, yh0 + (metrics.getHeight() / 2) - 3);
            if (i>0) {
                g2.drawString(Label, xv0 - labelWidth / 2, yv0 + metrics.getHeight() + 3);
            }
        }
        // * Chart border
        g2.drawLine(padding + labelPadding, getHeight() - padding - labelPadding, padding + labelPadding, padding);
        g2.drawLine(padding + labelPadding, getHeight() - padding - labelPadding, getWidth() - padding,
                getHeight() - padding - labelPadding);

        // * Chart Content
        Stroke oldStroke = g2.getStroke();
        g2.setColor(lineColor);
        g2.setStroke(GRAPH_STROKE);
        for (int i = 0; i < hull.size(); i++) {
            int x1 = hull.get(i).nodeA.x;
            int y1 = hull.get(i).nodeA.y;
            int x2 = hull.get(i).nodeB.x;
            int y2 = hull.get(i).nodeB.y;
            g2.drawLine(x1, y1, x2, y2);
        }
        g2.setStroke(oldStroke);
        g2.setColor(pointColor);
        for (int i = 0; i < fillPoints.size(); i++) {
            int x = fillPoints.get(i).x - pointWidth / 2;
            int y = fillPoints.get(i).y - pointWidth / 2;
            g2.fillOval(x, y, pointWidth, pointWidth);
            String Coor = "(" + ((int) (fill[i].x)) + "," + ((int) (fill[i].y)) + ")"; 
            g2.drawString(Coor, x-15, y-4);
        }   
    }
}

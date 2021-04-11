package com.company;

import javax.swing.*;
import java.awt.*;

public class Score extends JPanel {

    private static int score;
    private static  int POINTS_PER_TRIO;
    private static final JLabel scoreLabel= new JLabel("Score: 0");

    public Score() {
        score= 0;
        POINTS_PER_TRIO= 100;
        setBackground(Color.BLACK);
    }

    public static int getScore() {
        return score;
    }

    public void showLabel() {
        scoreLabel.setBounds(100, 100, 500, 400);
        scoreLabel.setText("Score: " + score);
        scoreLabel.setForeground(Color.RED);
        scoreLabel.setFont(new Font("Serif", Font.PLAIN, 36));
        add(scoreLabel);
        repaint();
    }

    public static void addScore() {
        score += POINTS_PER_TRIO;
    }

}

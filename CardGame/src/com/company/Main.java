package com.company;

import javax.swing.*;
import java.awt.*;
import java.awt.event.WindowAdapter;
import java.awt.event.WindowEvent;


public class Main extends JFrame {

    public static void createGame() {

        Table[] gui = {new Table()};
        Deck[] d= {new Deck()};
        Score[] s= {new Score()};
        Hand[] h= {new Hand()};
        Checker[] c= {new Checker()};
        JFrame[] frame = {new JFrame()};
        gui[0].makeTable();
        s[0].showLabel();
        h[0].makeHand();
        c[0].makeChecker();
        ButtonPanel[] b= {new ButtonPanel()};
        frame[0].setLayout(null);
        gui[0].setBounds(800,0,1060,800);
        frame[0].add(gui[0]);
        s[0].setBounds(800,800,1560,400);
        frame[0].add(s[0]);
        h[0].setBounds(0,0,800,300);
        frame[0].add(h[0]);
        c[0].setBounds(0,295,800, 500);
        frame[0].add(c[0]);
        b[0].setBounds(0, 790, 800,300 );
        frame[0].add(b[0]);
        frame[0].repaint();
        frame[0].setSize(1860, 1060);
        frame[0].setVisible(true);
        frame[0].setDefaultCloseOperation(WindowConstants.EXIT_ON_CLOSE);

        ButtonPanel.RESET_BUTTON.addActionListener(e -> {
            int response = JOptionPane.showConfirmDialog(frame[0], "Are you sure, you want to reset the game?", "NEW GAME", JOptionPane.YES_NO_OPTION);
            if (response == JOptionPane.YES_OPTION) {
                frame[0].dispose();
                frame[0] = new JFrame();
                gui[0] = new Table();
                d[0] = new Deck();
                s[0] = new Score();
                h[0] = new Hand();
                c[0] = new Checker();
                gui[0].makeTable();
                s[0].showLabel();
                h[0].makeHand();
                c[0].makeChecker();
                b[0] = new ButtonPanel();
                frame[0].setLayout(null);
                gui[0].setBounds(800, 0, 1060, 800);
                frame[0].add(gui[0]);
                s[0].setBounds(800, 800, 1560, 400);
                frame[0].add(s[0]);
                h[0].setBounds(0, 0, 800, 300);
                frame[0].add(h[0]);
                c[0].setBounds(0, 295, 800, 500);
                frame[0].add(c[0]);
                b[0].setBounds(0, 790, 800, 300);
                frame[0].add(b[0]);
                frame[0].repaint();
                frame[0].setSize(1860, 1060);
                frame[0].setVisible(true);
                frame[0].setDefaultCloseOperation(WindowConstants.EXIT_ON_CLOSE);
            }
        });


        final int[] x = {75};
        int y=60;
        ButtonPanel.DISCARD_BUTTON.addActionListener(e -> {

            for (int i = 0; i < Hand.getCardLabels().length; i++) {
                if (frame[0].getMostRecentFocusOwner() == Hand.cardLabel[i]) {
                    Hand.cardLabel[i].setIcon(Hand.aux);
                    Dimension size = Hand.cardLabel[i].getPreferredSize();
                    x[0] = x[0] + i * 120;
                    Hand.cardLabel[i].setBounds(x[0], y, size.width, size.height);
                    frame[0].repaint();
                    x[0] = 75;
                    Hand.hand.set(i, Card.empty);
                    Hand.cardLabel[i].setFocusable(false);
                    Hand.cardLabel[i].setFocusable(true);
                }
            }
        });



        ButtonPanel.ADD_BUTTON.addActionListener(e -> {

            for (int i = 0; i < Hand.getCardLabels().length; i++) {
                if (frame[0].getMostRecentFocusOwner() == Hand.cardLabel[i]) {
                    if (Checker.checker[0].getIcon() == Checker.auks) {
                        Checker.add(Hand.hand.get(i));
                        ImageIcon icon = CardsImages.getCard(Hand.hand.get(i));
                        Image resizeImage = icon.getImage();
                        Image modifyImage = resizeImage.getScaledInstance(170, 260, Image.SCALE_SMOOTH);
                        icon = new ImageIcon(modifyImage);
                        Checker.checker[0].setIcon(icon);
                        frame[0].repaint();
                    } else if (Checker.checker[1].getIcon() == Checker.auks) {
                        Checker.add(Hand.hand.get(i));
                        ImageIcon icon = CardsImages.getCard(Hand.hand.get(i));
                        Image resizeImage = icon.getImage();
                        Image modifyImage = resizeImage.getScaledInstance(170, 260, Image.SCALE_SMOOTH);
                        icon = new ImageIcon(modifyImage);
                        Checker.checker[1].setIcon(icon);
                        frame[0].repaint();
                    } else if (Checker.checker[2].getIcon() == Checker.auks) {
                        Checker.add(Hand.hand.get(i));
                        ImageIcon icon = CardsImages.getCard(Hand.hand.get(i));
                        Image resizeImage = icon.getImage();
                        Image modifyImage = resizeImage.getScaledInstance(170, 260, Image.SCALE_SMOOTH);
                        icon = new ImageIcon(modifyImage);
                        Checker.checker[2].setIcon(icon);
                        frame[0].repaint();
                        if(Checker.isSequentialTrio()) {
                            for(int a=0; a<5; a++) {
                                if(Checker.checkerField.contains(Hand.hand.get(a))) {
                                    Hand.cardLabel[a].setIcon(Hand.aux);
                                    frame[0].repaint();
                                }
                            }
                            Checker.addScoreRemoveCards();
                            s[0].showLabel();
                            c[0].resetChecker();
                            frame[0].repaint();
                        }
                        else {
                            Checker.checkerField.clear();
                            c[0].resetChecker();
                            frame[0].repaint();
                        }
                    }
                }
            }
        });

        frame[0].addWindowListener(new WindowAdapter() {
            @Override
            public void windowClosing(WindowEvent e) {
                if(Score.getScore() >= 400) {
                    JOptionPane.showMessageDialog(
                            frame[0],
                            "Congratulations, you've scored over 400 points, very impressive!",
                            "CONGRATULATIONS, YOU WON",
                            JOptionPane.INFORMATION_MESSAGE);
                }
                else {
                    JOptionPane.showMessageDialog(
                            frame[0],
                            "You've scored below the winning boundary, nevertheless you should be very proud of yourself. Keep it going",
                            "BETTER LUCK NEXT TIME",
                            JOptionPane.INFORMATION_MESSAGE);
                }
            }
        });

    }

    public static void main(String[] args) {

        SwingUtilities.invokeLater(Main::createGame);

    }
}
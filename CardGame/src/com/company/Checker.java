package com.company;

import javax.swing.*;
import java.awt.*;
import java.util.ArrayList;
import java.util.Comparator;
import java.util.HashSet;
import java.util.Objects;

public class Checker extends JPanel {

    public static HashSet<Card> checkerField;
    private final Score score= new Score();
    public static JLabel [] checker = new JLabel[3];


    private static final ImageIcon temp= Card.globalX;
    private static final Image resizeImg = temp.getImage();
    private static final Image modifyImg = resizeImg.getScaledInstance(170, 260, Image.SCALE_SMOOTH);
    public static ImageIcon auks = new ImageIcon(modifyImg);


    public Checker() {
        checkerField = new HashSet<>();
        setBackground( Color.BLACK);
        setLayout(null);
    }

    public static void add(Card card) {
        checkerField.add(card);
    }


    public boolean isSameColor() {
        if(checkerField.size() == 3) {
            ArrayList<Card> list = new ArrayList<>(checkerField);
            Card.Colors color= null;
            for(Card each : list) {
                if(color == null) {
                    color= each.getColor();
                }
                else if(color.ordinal() != each.getColor().ordinal()) {
                    return false;
                }
            }
        return true;
        }
        return false;
    }

    static class SortByValue implements Comparator<Card> {
        @Override
        public int compare(Card card, Card card2) {
                return card.getValue().ordinal() - card2.getValue().ordinal();
        }
    }

    public static boolean isSequentialTrio() {
        if(checkerField.size() == 3) {
            ArrayList<Card> list= new ArrayList<>(checkerField);
            list.sort(new SortByValue());
            Card.Colors color= null;
            Card.Values previous_value= null;
            int a=0;
            for(Card each : list) {
                if(color == null) {
                    color= each.getColor();
                }
                if(previous_value == null) {
                    previous_value= each.getValue();
                }
                else if( (previous_value.ordinal() != (each.getValue().ordinal() - a)) || color != each.getColor()) {
                    return false;
                }
                a++;
            }
            return true;
        }
        return false;
    }

    public static void addScoreRemoveCards() {
            checkerField.clear();
            Score.addScore();
    }
    public void makeChecker() {
        int x=60;
        int y=70;
        ImageIcon checkerFrame = new ImageIcon((Objects.requireNonNull(Table.class.getResource("/resources/checkerNew.png"))));
        Image resizeImage = checkerFrame.getImage();
        Image modifyImage = resizeImage.getScaledInstance(700, 400, Image.SCALE_SMOOTH);
        checkerFrame = new ImageIcon(modifyImage);
        JLabel checkerLabel = new JLabel(checkerFrame);
        Dimension size = checkerLabel.getPreferredSize();
        checkerLabel.setBounds(100, 10, size.width, size.height);
        add(checkerLabel);
        for(int i=0; i<3; i++) {
            ImageIcon checkerCard = auks;
            checker[i] = new JLabel(checkerCard);
            Dimension sizer = checker[i].getPreferredSize();
            checker[i].setBounds(x, y, sizer.width, sizer.height);
            checkerLabel.add(checker[i]);
            repaint();
            x= x+ 200;
        }
    }
    public void resetChecker() {
        int x=60;
        int y=70;
        for(int i=0; i<3; i++) {
            ImageIcon checkerCard = auks;
            checker[i].setIcon(checkerCard);
            repaint();
            x = x + 200;
        }
    }
}

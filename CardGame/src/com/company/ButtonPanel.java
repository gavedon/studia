package com.company;

import javax.swing.*;
import javax.swing.border.LineBorder;
import java.awt.*;



public class ButtonPanel extends JPanel {

    public static final JButton DISCARD_BUTTON= new JButton("DISCARD");
    public static final JButton RESET_BUTTON= new JButton("RESET");
    public static final JButton ADD_BUTTON= new JButton("ADD");
    private final Checker checker= new Checker();

    public ButtonPanel() {

        setBackground( Color.BLACK);
        setLayout(null);

        DISCARD_BUTTON.setBounds(100, 100, 200, 100);
        DISCARD_BUTTON.setForeground(Color.YELLOW);
        DISCARD_BUTTON.setBackground(Color.BLACK);
        DISCARD_BUTTON.setFocusPainted(false);
        DISCARD_BUTTON.setBorder(new LineBorder(Color.YELLOW));
        DISCARD_BUTTON.setFont(new Font("Serif", Font.PLAIN, 27));
        DISCARD_BUTTON.setFocusable(false);
        add(DISCARD_BUTTON);
        repaint();



        RESET_BUTTON.setBounds(560, 100, 200, 100);
        RESET_BUTTON.setForeground(Color.YELLOW);
        RESET_BUTTON.setBackground(Color.BLACK);
        RESET_BUTTON.setFocusPainted(false);
        RESET_BUTTON.setBorder(new LineBorder(Color.YELLOW));
        RESET_BUTTON.setFont(new Font("Serif", Font.PLAIN, 27));
        RESET_BUTTON.setFocusable(false);
        add(RESET_BUTTON);
        repaint();


        ADD_BUTTON.setBounds(330, 100, 200, 100);
        ADD_BUTTON.setForeground(Color.YELLOW);
        ADD_BUTTON.setBackground(Color.BLACK);
        ADD_BUTTON.setFocusPainted(false);
        ADD_BUTTON.setBorder(new LineBorder(Color.YELLOW));
        ADD_BUTTON.setFont(new Font("Serif", Font.PLAIN, 27));
        ADD_BUTTON.setFocusable(false);
        add(ADD_BUTTON);
        repaint();


    }
}

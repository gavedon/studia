package com.company;

import javax.swing.*;
import java.awt.*;
import java.awt.event.FocusAdapter;
import java.awt.event.FocusEvent;
import java.awt.event.MouseAdapter;
import java.awt.event.MouseEvent;
import java.io.Serializable;
import java.util.ArrayList;


public class Hand  extends JPanel implements Serializable {

    public static  ArrayList<Card> hand;
    private static Deck stackOfCards;
    private static final int MAX_NUMBER_OF_CARDS_IN_HAND= 5;

    private static final ImageIcon temp= Card.global;
    private static final Image resizeImg = temp.getImage();
    private static final Image modifyImg = resizeImg.getScaledInstance(100, 150, Image.SCALE_SMOOTH);
    public static ImageIcon aux = new ImageIcon(modifyImg);

    public static JLabel[] cardLabel = new JLabel[5];

    public Hand() {
        hand= new ArrayList<>();
        stackOfCards= new Deck();
        stackOfCards.shuffleRandomly();
        setBackground( Color.BLACK);
        setLayout(null);
        Dimension size = this.getPreferredSize();
    }

    public Card addCard() {
        return stackOfCards.pop();
    }


    public static int remove(Card card) {
        int hilfer= hand.indexOf(card);
        hand.remove(card);
        return hilfer;
    }


    public boolean isFull() {
        return hand.size() == MAX_NUMBER_OF_CARDS_IN_HAND;
    }



    public void makeHand() {
        int x=75;
        int y=60;
        JLabel helper = new JLabel(aux);
        Dimension size2 = helper.getPreferredSize();
        helper.setBounds(75, 60, size2.width, size2.height);
        helper.setFocusable(true);
        Icon help= helper.getIcon();
        repaint();

        for(int k=0; k<MAX_NUMBER_OF_CARDS_IN_HAND; k++) {
            if (getStack() != null) {
                Card temp = addCard();
                hand.add(temp);
                ImageIcon picture = CardsImages.getCard(temp);
                Image resizeImage = picture.getImage();
                Image modifyImage = resizeImage.getScaledInstance(100, 150, Image.SCALE_SMOOTH);
                picture = new ImageIcon(modifyImage);
                cardLabel[k] = new JLabel(picture);
                Dimension size = cardLabel[k].getPreferredSize();
                cardLabel[k].setBounds(x, y, size.width, size.height);
                cardLabel[k].setFocusable(true);
                int finalK = k;
                cardLabel[k].addFocusListener(new FocusAdapter() {
                    @Override
                    public void focusGained(FocusEvent e) {
                        cardLabel[finalK].setBorder(BorderFactory.createLineBorder(Color.YELLOW));
                        if (getStack() != null) {
                            if (cardLabel[finalK].getIcon() == help) {
                                Card temp2 = addCard();
                                hand.set(finalK, temp2);
                                ImageIcon picture2 = CardsImages.getCard(temp2);
                                Image resizeImg = picture2.getImage();
                                Image modifyImg = resizeImg.getScaledInstance(100, 150, Image.SCALE_SMOOTH);
                                picture2 = new ImageIcon(modifyImg);
                                cardLabel[finalK].setIcon(picture2);
                            }
                        } else {
                            cardLabel[finalK].setIcon(null);
                        }
                    }

                    @Override
                    public void focusLost(FocusEvent e) {
                        cardLabel[finalK].setBorder(null);
                    }
                });
                cardLabel[k].addMouseListener(new MouseAdapter() {
                    @Override
                    public void mousePressed(MouseEvent e) {
                        cardLabel[finalK].requestFocusInWindow();
                    }
                });
                add(cardLabel[k]);
                repaint();
                x = x + 120;
            }
            else {
                cardLabel[k].setIcon(null);
            }
        }
    }

    public static JLabel[] getCardLabels() {
        return cardLabel;
    }

    public static Deck getStack() {
        return stackOfCards;
    }


}

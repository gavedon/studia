package com.company;


import javax.swing.*;
import java.util.HashMap;
import java.util.Objects;

public class CardsImages {

    private static final String IMAGE_PATH= "/resources/";
    private static final String IMAGE_EXTENSION= ".png";
    private static final String[] COLORS_FIRST_LETTERS= {"O", "G", "B"};
    private static final String[] VALUES_AS_NUMBERS= {"1", "2", "3", "4", "5", "6", "7", "8"};

    private static final HashMap<String, ImageIcon> allCards = new HashMap<String, ImageIcon>();
    private static final HashMap<ImageIcon, String > allCards_reversed= new HashMap<ImageIcon, String>();
    public static final HashMap<JLabel, Card> ImagesAsLabels= new HashMap<JLabel, Card>();



    public CardsImages() {};

    private static String getCode(Card card) {
        return COLORS_FIRST_LETTERS[ card.getColor().ordinal()] + VALUES_AS_NUMBERS[ card.getValue().ordinal()];
    }

    private static ImageIcon getCard_help( String code ) {
        ImageIcon anIcon = allCards.get(code);
        if( anIcon == null ) {
            anIcon = new ImageIcon((Objects.requireNonNull(CardsImages.class.getResource(IMAGE_PATH + code + IMAGE_EXTENSION)))); //moze tu byc classloader potem, pamietaj
            allCards.put( code, anIcon );
        }
        return anIcon;
    }
    public static Card getCard_helper( String code ) {
        int temp=0;
        int aux=0;
        String substring= code.substring(11,13);
        for(String s : COLORS_FIRST_LETTERS) {
            for(String i : VALUES_AS_NUMBERS) {
                if((s + i).equals(substring)) {
                    Card.Colors color= Card.Colors.values()[temp];
                    Card.Values value= Card.Values.values()[aux];
                    return new Card(color, value);
                }
                aux++;
            }
            temp++;
        }
        return null;
    }

    public static ImageIcon getCard(Card card) {
        return getCard_help( getCode(card));
    }

    public void makeReverse() {
        for (String i : allCards.keySet()) {
            allCards_reversed.put(allCards.get(i), i);
        }
    }
    public void addLabel() {
        for(ImageIcon i : allCards_reversed.keySet()) {
            String hashvalue= allCards_reversed.get(i);
            ImagesAsLabels.put(new JLabel(i), getCard_helper(hashvalue));
        }
    }

}

package com.company;

import javax.swing.*;
import java.io.Serializable;
import java.util.Objects;

public class Card implements Serializable, Comparable<Card> {

    public enum  Colors {ORANGE, GREEN, BLUE}

    public enum Values {ONE, TWO, THREE, FOUR, FIVE, SIX, SEVEN, EIGHT}

    public static final ImageIcon global = new ImageIcon((Objects.requireNonNull(Card.class.getResource("/resources/mark.png"))));
    public static final ImageIcon globalX = new ImageIcon((Objects.requireNonNull(Card.class.getResource("/resources/checkerCard.png"))));
    public static final Card empty = null;


    private final Colors color;
    private final Values value;

    public Card(Colors constructorColor, Values constructorValue) {
        color= constructorColor;
        value= constructorValue;

    }

    public Colors getColor() {
        return color;
    }

    public Values getValue() {
        return value;
    }



    public String toString() {
        return color + " " + value;
    }


    public int compareTo(Card card) {
        if (card == null) {
            return -1;
        }
        if(color.ordinal() == card.color.ordinal()) {
            if (this.value.ordinal() < card.value.ordinal()) {
                return -1;
            }
            else {return 1;} //no need to check whether its equal, coz its one unique card per game
        }
        else {return -1;}
    }


}

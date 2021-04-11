package com.company;

import java.io.Serializable;
import java.util.*;
import com.company.Card.*;


public class Deck implements Serializable {

    private final Stack<Card> cards;

    public Deck() {
        cards= new Stack<>();
    }

    public void reset() {
        cards.clear();
        for(Colors each : Colors.values()) {
            for(Values every : Values.values()) {
                cards.add(new Card(each, every));
            }
        }
    }

    public Card pop() {  //return popped card from the stack
        return cards.pop();
    }




    public void removeACard(Card card) {
        if(card != null) {
            Colors temp = card.getColor();
            Values aux = card.getValue();
            for (Card each : cards) {
                if (each.getColor() == temp) {
                    if (each.getValue() == aux) {
                        cards.remove(card);
                    }
                }
            }
        }
    }

    public void removeAll() {
        cards.clear();
    }

    public int size() {
        return cards.size();
    }

    public void shuffleRandomly() {
        reset();
        int auxSize= size();
        List<Card> listOfCards = new ArrayList<>();
        for(int k=0; k<auxSize; k++) {
            Card temp = cards.pop();
            listOfCards.add(temp);
        }
        Collections.shuffle(listOfCards, new Random());
        int a= 0;
        while(a != listOfCards.size()) {
            cards.add(listOfCards.get(a));
            a++;
        }
    }



}

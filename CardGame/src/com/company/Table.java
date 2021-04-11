package com.company;


import javax.swing.*;
import java.awt.*;
import java.awt.event.MouseAdapter;
import java.awt.event.MouseEvent;
import java.util.Objects;

public class Table extends JPanel {

    private static final JButton[] buttons = new JButton[24];
    private static final String[] buttons_help= new String[24];
    public static final String[] COLORS_FIRST_LETTERS= {"O", "G", "B"};
    public static final String[] VALUES_AS_NUMBERS= {"1", "2", "3", "4", "5", "6", "7", "8"};

    public Table() {
        setBackground( Color.BLACK);
        setLayout(null);
    }

    void makeTable() {
        int x = 80;
        int y = 200;
        int a = 0;
        int h= 0;
        int j=0;
        for (Card.Colors each : Card.Colors.values()) {
            for (Card.Values every : Card.Values.values()) {
                Card card_aux = new Card(each, every);
                ImageIcon picture = CardsImages.getCard(card_aux);
                Image resizeImage = picture.getImage();
                Image modifyImage = resizeImage.getScaledInstance(100, 150, Image.SCALE_SMOOTH);
                picture = new ImageIcon(modifyImage);
                JButton pic = new JButton(picture);
                pic.setBackground(Color.BLACK);
                pic.setBorderPainted(false);
                pic.setFocusPainted(false);
                pic.setContentAreaFilled(false);
                Dimension size = pic.getPreferredSize();
                pic.setBounds(x, y, size.width, size.height);
                x = x + 120;
                buttons[a] = pic;
                add(pic);
                a++;
            }
            y = y + 160;
            x = x - 120 * 8;
        }
        ImageIcon title = new ImageIcon((Objects.requireNonNull(Table.class.getResource("/resources/title.png"))));
        JLabel titleLabel = new JLabel(title);
        Dimension size = titleLabel.getPreferredSize();
        titleLabel.setBounds(400, 10, size.width, size.height);
        add(titleLabel);
        repaint();

        for (int k=0; k<Card.Colors.values().length; k++) {
            for (int i=0; i<Card.Values.values().length; i++) {
                buttons_help[j]= ""+ COLORS_FIRST_LETTERS[k] + VALUES_AS_NUMBERS[i] + "";
                j++;
            }
        }

        final ImageIcon[] ex = {new ImageIcon((Objects.requireNonNull(Table.class.getResource("/resources/X.png"))))};
        Image resizeImg = ex[0].getImage();
        Image modifyImg = resizeImg.getScaledInstance(100, 150, Image.SCALE_SMOOTH);
        ex[0] = new ImageIcon(modifyImg);
        for (JButton button : buttons) {
            int finalH = h;
            button.addMouseListener(new MouseAdapter() {
                public void mousePressed(MouseEvent arg0) {
                    if (button.getIcon() != ex[0]) {
                        button.setIcon(ex[0]);
                    } else {
                        ImageIcon help = new ImageIcon((Objects.requireNonNull(Table.class.getResource("/resources/" + buttons_help[finalH] + ".png"))));
                        Image resize = help.getImage();
                        Image modify = resize.getScaledInstance(100, 150, Image.SCALE_SMOOTH);
                        help = new ImageIcon(modify);
                        button.setIcon(help);
                    }
                }
            });
            h++;
            repaint();
        }
    }
}


/*******************************************************************************
*
* Plugex - PLUGin EXamples
* Author: Olivier Bélanger
*
* Ce fichier d'en-tête est destiné à être utilisé par tous les plugiciels de
* l'ensemble Plugex. Il définit le style visuel commun à tous les plugiciels.
*
* La méthode setTheme(String newTheme) peut être appelée pour définir la couleur
* dominante du thème. Les valeurs possibles sont: blue, grey, red, green, orange
* ou purple.
*
*******************************************************************************/

#pragma once

#include "../JuceLibraryCode/JuceHeader.h"

// Notre LookAndFeel hérite de la version 4 du LookAndFeel par défaut de Juce.
// Cette classe n'a donc besoin de définir que les méthodes nécessaires pour 
// modifier l'apparence des objets graphiques utilisés par l'ensemble de plugiciels.
class CustomLookAndFeel : public juce::LookAndFeel_V4
{
public:
    // Le thème par defaut, définit dans le constructeur est le thème bleu.
    CustomLookAndFeel() {
        setTheme("grey");
    }

    // Méthode permettant de changer le thème visuel du plugiciel. Les différents thèmes
    // se différencient par leur couleur dominante.
    bool setTheme(juce::String newTheme) {
        const juce::StringArray themes = juce::StringArray("blue", "green", "red", "orange", "purple", "grey", "steal",
                                               "lightblue", "lightgreen", "pink");
        if (! themes.contains(newTheme)) {
            return false;
        }

        //Colour darktheme, lighttheme;
        juce::Colour light = juce::Colour(212, 211, 224);

        if (newTheme == "blue") {
            darktheme = juce::Colour(6, 28, 64);
            lighttheme = juce::Colour(113, 137, 209);
        } else if (newTheme == "grey") {
            darktheme = juce::Colour(87, 87, 87);
            lighttheme = juce::Colour(209, 209, 209);
        } else if (newTheme == "red") {
            darktheme = juce::Colour(61, 7, 7);
            lighttheme = juce::Colour(232, 70, 70);
        } else if (newTheme == "green") {
            darktheme = juce::Colour(6, 54, 20);
            lighttheme = juce::Colour(24, 191, 26);
        } else if (newTheme == "orange") {
            darktheme = juce::Colour(56, 37, 7);
            lighttheme = juce::Colour(191, 127, 23);
        } else if (newTheme == "purple") {
            darktheme = juce::Colour(48, 6, 54);
            lighttheme = juce::Colour(190, 25, 212);
        } else if (newTheme == "steal") {
            darktheme = juce::Colour(35, 46, 54);
            lighttheme = juce::Colour(118, 154, 181);
        } else if (newTheme == "lightblue") {
            darktheme = juce::Colour(13, 69, 65);
            lighttheme = juce::Colour(33, 184, 174);
        } else if (newTheme == "lightgreen") {
            darktheme = juce::Colour(39, 56, 5);
            lighttheme = juce::Colour(120, 171, 17);
        } else if (newTheme == "pink") {
            darktheme = juce::Colour(56, 6, 40);
            lighttheme = juce::Colour(184, 18, 131);
        }

        // Fenêtre principale.
        setColour(juce::ResizableWindow::backgroundColourId, darktheme);

        // Bubble
        setColour(juce::BubbleComponent::backgroundColourId, darktheme);

        // Étiquette.
        setColour(juce::Label::textColourId, light);
        setColour(juce::Label::textWhenEditingColourId, light);
        setColour(juce::Label::outlineWhenEditingColourId, juce::Colours::transparentBlack);
        setColour(juce::Label::backgroundWhenEditingColourId, juce::Colours::transparentBlack);

        // Potentiomètre.
        setColour(juce::Slider::textBoxTextColourId, light);
        setColour(juce::Slider::textBoxOutlineColourId, juce::Colours::transparentBlack);
        setColour(juce::Slider::textBoxHighlightColourId, lighttheme.withAlpha(0.5f));
        setColour(juce::Slider::backgroundColourId, juce::Colours::transparentBlack);
        setColour(juce::Slider::rotarySliderOutlineColourId, lighttheme);
        setColour(juce::Slider::rotarySliderFillColourId, lighttheme.withAlpha(0.25f));
        setColour(juce::Slider::trackColourId, lighttheme.withAlpha(0.25f));
        setColour(juce::Slider::thumbColourId, lighttheme);

        // Menu déroulant.
        setColour(juce::ComboBox::backgroundColourId, juce::Colours::transparentBlack);
        setColour(juce::ComboBox::textColourId, light);
        setColour(juce::ComboBox::outlineColourId, lighttheme);
        setColour(juce::ComboBox::buttonColourId, lighttheme);
        setColour(juce::ComboBox::arrowColourId, lighttheme);
        setColour(juce::ComboBox::focusedOutlineColourId, lighttheme);
        setColour(juce::PopupMenu::backgroundColourId, darktheme);
        setColour(juce::PopupMenu::textColourId, light);
        setColour(juce::PopupMenu::highlightedBackgroundColourId, lighttheme.withAlpha(0.25f));
        setColour(juce::PopupMenu::highlightedTextColourId, light);

        // Boutons.
        setColour(juce::TextButton::buttonColourId, darktheme);
        setColour(juce::TextButton::buttonOnColourId, lighttheme.withAlpha(0.25f));
        setColour(juce::TextButton::textColourOnId, light);
        setColour(juce::TextButton::textColourOffId, light);
        setColour(juce::ToggleButton::textColourId, light);
        setColour(juce::ToggleButton::tickColourId, juce::Colour(113, 192, 249));
        setColour(juce::ToggleButton::tickDisabledColourId, lighttheme);

        return true;
    }

    juce::Colour getDarkTheme() {
        return darktheme;
    }

    juce::Colour getLightTheme() {
        return lighttheme;
    }

    juce::Colour getLightFadeTheme() {
        return lighttheme.withAlpha(0.25f);
    }

    // Redéfinition de la méthode pour dessiner un potentiomètre en forme de bouton rond (knob).
    void drawRotarySlider(juce::Graphics& g, int x, int y, int width, int height, float sliderPos,
                          const float rotaryStartAngle, const float rotaryEndAngle, juce::Slider& slider) {
        auto bounds = juce::Rectangle<int> ((width - height) / 2.0f, y, height, height).toFloat().reduced (10);

        auto radius = juce::jmin (bounds.getWidth(), bounds.getHeight()) / 2.0f;
        auto toAngle = rotaryStartAngle + sliderPos * (rotaryEndAngle - rotaryStartAngle);
        auto lineW = juce::jmin (1.5f, radius * 0.5f);
        auto arcRadius = radius - lineW * 0.5f;

        juce::Path background;
        background.addEllipse (bounds);
        g.setColour (slider.findColour (juce::Slider::rotarySliderOutlineColourId));
        g.strokePath (background, juce::PathStrokeType (lineW, juce::PathStrokeType::curved, juce::PathStrokeType::rounded));

        if (slider.isEnabled()) {
            juce::Path value;
            value.addPieSegment (bounds, rotaryStartAngle, toAngle, 0.0f);
            g.setColour (slider.findColour (juce::Slider::rotarySliderFillColourId));
            g.fillPath (value);
        }

        juce::Path thumb;
        juce::Point<float> thumbPoint (bounds.getCentreX() + arcRadius * std::cos (toAngle - juce::MathConstants<float>::halfPi),
                                 bounds.getCentreY() + arcRadius * std::sin (toAngle - juce::MathConstants<float>::halfPi));

        g.setColour (slider.findColour (juce::Slider::thumbColourId));
        thumb.addLineSegment (juce::Line<float> (bounds.getCentre(), thumbPoint), 1.5f);
        g.strokePath(thumb, juce::PathStrokeType (lineW, juce::PathStrokeType::curved, juce::PathStrokeType::rounded));
    }
    
    // Redéfinition de la méthode pour dessiner un potentiomètre linéaire (traditionnel vertical ou horizontal et
    // rectangulaire plein avec la valeur écrite dans le potentiomètre, vertical ou horizontal).
    void drawLinearSlider ( juce::Graphics& g, int x, int y, int width, int height, float sliderPos,
                            float minSliderPos, float maxSliderPos, const juce::Slider::SliderStyle style,
                            juce::Slider& slider) {
        if (slider.isBar()) {
            g.setColour (slider.findColour (juce::Slider::rotarySliderOutlineColourId));
            g.drawRect(juce::Rectangle<float>(0.f, 0.f, width, height));
            if (slider.isHorizontal()) {
                float linePos = sliderPos < 0.0f ? 0.0f : sliderPos > width ? width : sliderPos;
                g.drawLine(juce::Line<float>(linePos, y + 1.0f, linePos, height - 2.0f));
                g.setColour (slider.findColour (juce::Slider::trackColourId));
                g.fillRect(juce::Rectangle<float> (static_cast<float> (x), y + 1.0f, sliderPos - x - 1.0f, height - 2.0f));
            } else {
                float linePos = sliderPos < 0.0f ? 0.0f : sliderPos > height ? height : sliderPos;
                g.drawLine(juce::Line<float>(x = 1.0f, linePos, width - 2.0f, linePos));
                g.setColour (slider.findColour (juce::Slider::trackColourId));
                g.fillRect(juce::Rectangle<float>(x + 1.0f, sliderPos, width - 2.0f, y + (height - sliderPos - 2.0f)));
            }
        }
        else {
            auto isTwoVal   = (style == juce::Slider::SliderStyle::TwoValueVertical   || style == juce::Slider::SliderStyle::TwoValueHorizontal);
            auto isThreeVal = (style == juce::Slider::SliderStyle::ThreeValueVertical || style == juce::Slider::SliderStyle::ThreeValueHorizontal);

            auto trackWidth = juce::jmin (6.0f, slider.isHorizontal() ? height * 0.25f : width * 0.25f);

            juce::Point<float> startPoint (slider.isHorizontal() ? x : x + width * 0.5f,
                                     slider.isHorizontal() ? y + height * 0.5f : height + y);

            juce::Point<float> endPoint (slider.isHorizontal() ? width + x : startPoint.x,
                                   slider.isHorizontal() ? startPoint.y : y);

            juce::Rectangle<float> track = slider.isHorizontal() ? juce::Rectangle<float>(x, y, width, height).withSizeKeepingCentre(width, height * 0.25f) :
                juce::Rectangle<float>(x, y, width, height).withSizeKeepingCentre(juce::jmin(6.0f, width * 0.1f), height);
            g.setColour (slider.findColour (juce::Slider::rotarySliderOutlineColourId));
            g.drawRect(track);

            juce::Point<float> minPoint, maxPoint, thumbPoint;

            if (isTwoVal || isThreeVal)
            {
                minPoint = { slider.isHorizontal() ? minSliderPos : width * 0.5f,
                             slider.isHorizontal() ? height * 0.5f : minSliderPos };

                if (isThreeVal)
                    thumbPoint = { slider.isHorizontal() ? sliderPos : width * 0.5f,
                                   slider.isHorizontal() ? height * 0.5f : sliderPos };

                maxPoint = { slider.isHorizontal() ? maxSliderPos : width * 0.5f,
                             slider.isHorizontal() ? height * 0.5f : maxSliderPos };
            }
            else
            {
                auto kx = slider.isHorizontal() ? sliderPos : (x + width * 0.5f);
                auto ky = slider.isHorizontal() ? (y + height * 0.5f) : sliderPos;

                minPoint = startPoint;
                maxPoint = { kx, ky };
            }

            auto thumbWidth = slider.isHorizontal() ? 6.0f : width * 0.33f;
            auto thumbHeight = slider.isHorizontal() ? height * 0.8f : 6.0f;

            if (! isTwoVal)
            {
                g.setColour (slider.findColour (juce::Slider::thumbColourId));
                g.fillRect (juce::Rectangle<float> (thumbWidth, thumbHeight).withCentre (isThreeVal ? thumbPoint : maxPoint));
            }

            if (isTwoVal || isThreeVal)
            {
                auto sr = juce::jmin (trackWidth, (slider.isHorizontal() ? height : width) * 0.4f);
                auto pointerColour = slider.findColour (juce::Slider::thumbColourId);

                if (slider.isHorizontal())
                {
                    drawPointer (g, minSliderPos - sr,
                        juce::jmax (0.0f, y + height * 0.5f - trackWidth * 2.0f),
                                 trackWidth * 2.0f, pointerColour, 2);

                    drawPointer (g, maxSliderPos - trackWidth,
                        juce::jmin (y + height - trackWidth * 2.0f, y + height * 0.5f),
                                 trackWidth * 2.0f, pointerColour, 4);
                }
                else
                {
                    drawPointer (g, juce::jmax (0.0f, x + width * 0.5f - trackWidth * 2.0f),
                                 minSliderPos - trackWidth,
                                 trackWidth * 2.0f, pointerColour, 1);

                    drawPointer (g, juce::jmin (x + width - trackWidth * 2.0f, x + width * 0.5f), maxSliderPos - sr,
                                 trackWidth * 2.0f, pointerColour, 3);
                }
            }
        }
    }

    // Redéfinition de la méthode pour dessiner un menu déroulant.
    void drawComboBox (juce::Graphics& g, int width, int height, bool, int, int, int, int, juce::ComboBox& box) {
        juce::Rectangle<int> boxBounds (0, 0, width, height);

        g.setColour (box.findColour (juce::ComboBox::backgroundColourId));
        g.fillRect (boxBounds.toFloat());

        g.setColour (box.findColour (juce::ComboBox::outlineColourId));
        g.drawRect (boxBounds.toFloat());

        juce::Rectangle<int> arrowZone (width - 30, 0, 20, height);
        juce::Path path;
        path.startNewSubPath (arrowZone.getX() + 3.0f, arrowZone.getCentreY() - 3.0f);
        path.lineTo (static_cast<float> (arrowZone.getCentreX()), arrowZone.getCentreY() + 3.0f);
        path.lineTo (arrowZone.getRight() - 3.0f, arrowZone.getCentreY() - 3.0f);

        g.setColour (box.findColour (juce::ComboBox::arrowColourId).withAlpha ((box.isEnabled() ? 0.9f : 0.2f)));
        g.fillPath (path);
    }
    
    // Redéfinition de la méthode pour dessiner les boutons.
    void drawButtonBackground (juce::Graphics& g, juce::Button& button, const juce::Colour& backgroundColour,
                               bool shouldDrawButtonAsHighlighted, bool shouldDrawButtonAsDown) {
        auto bounds = button.getLocalBounds().toFloat();

        auto baseColour = backgroundColour.withMultipliedSaturation (button.hasKeyboardFocus (true) ? 1.3f : 0.9f)
                                          .withMultipliedAlpha (button.isEnabled() ? 1.0f : 0.5f);

        if (shouldDrawButtonAsDown || shouldDrawButtonAsHighlighted)
            baseColour = baseColour.contrasting (shouldDrawButtonAsDown ? 0.2f : 0.05f);

        g.setColour (baseColour);

        if (button.isConnectedOnLeft() || button.isConnectedOnRight())
        {
            juce::Path path;
            path.addRectangle (bounds.getX(), bounds.getY(), bounds.getWidth(), bounds.getHeight());

            g.fillPath (path);

            g.setColour (button.findColour (juce::ComboBox::outlineColourId));
            g.strokePath (path, juce::PathStrokeType (1.0f));
        }
        else
        {
            g.fillRect (bounds);

            g.setColour (button.findColour (juce::ComboBox::outlineColourId));
            g.drawRect (bounds, 1.0f);
        }
    }

    // Redéfinition de la méthode pour dessiner le bouton à deux états.
    void drawToggleButton (juce::Graphics& g, juce::ToggleButton& button,
                           bool shouldDrawButtonAsHighlighted, bool shouldDrawButtonAsDown) {
        auto fontSize = juce::jmin (15.0f, button.getHeight() * 0.75f);
        auto tickWidth = fontSize * 1.1f;

        drawTickBox (g, button, 4.0f, (button.getHeight() - tickWidth) * 0.5f,
                     tickWidth, tickWidth,
                     button.getToggleState(),
                     button.isEnabled(),
                     shouldDrawButtonAsHighlighted,
                     shouldDrawButtonAsDown);

        g.setColour (button.findColour (juce::ToggleButton::textColourId));
        g.setFont (fontSize);

        if (! button.isEnabled())
            g.setOpacity (0.5f);

        g.drawFittedText (button.getButtonText(),
                          button.getLocalBounds().withTrimmedLeft (juce::roundToInt (tickWidth) + 10)
                                                 .withTrimmedRight (2),
            juce::Justification::centredLeft, 10);
    }

    // Redéfinition de la méthode pour dessiner la case à cocher du bouton à deux états.
    void drawTickBox (juce::Graphics& g, juce::Component& component, float x, float y, float w, float h,
                                      const bool ticked, const bool isEnabled,
                                      const bool shouldDrawButtonAsHighlighted,
                                      const bool shouldDrawButtonAsDown) {
        juce::ignoreUnused (shouldDrawButtonAsHighlighted, shouldDrawButtonAsDown);

        juce::Rectangle<float> tickBounds (x, y, w, h);

        g.setColour (component.findColour (juce::ToggleButton::tickDisabledColourId));
//        g.setColour (component.findColour(isEnabled ? juce::ToggleButton::tickColourId : juce::ToggleButton::tickDisabledColourId));
        g.drawRect (tickBounds, 1.0f);

        if (ticked) {
            g.setColour (component.findColour (juce::ToggleButton::tickColourId));
            g.fillRect(tickBounds.reduced(3.0f, 3.0f));
        }
    }

private:
    juce::Colour darktheme;
    juce::Colour lighttheme;
};
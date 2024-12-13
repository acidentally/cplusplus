import java.net.URL;

import javax.sound.sampled.AudioInputStream;
import javax.sound.sampled.AudioSystem;
import javax.sound.sampled.Clip;

public class sound {

    Clip clip;
    URL soundURL[] = new URL[3];

    public sound() {
        soundURL[0] = getClass().getResource("./sound/sfx_wing.wav");
        soundURL[1] = getClass().getResource("./sound/sfx_hit.wav");
        soundURL[2] = getClass().getResource("./sound/sfx_point.wav");
    }

    // sound selection by using an array of sounds
    public void setFile(int i) {
        try {
            AudioInputStream ais = AudioSystem.getAudioInputStream(soundURL[i]);
            clip = AudioSystem.getClip();
            clip.open(ais);
        } catch (Exception e) {
        }
    }

    public void play() {
        clip.start();
    }

    public void stop() {
        clip.stop();
    }

}

#ifndef MediaPlayerENTITY_H
#define MediaPlayerENTITY_H

#include <entity.h>

class MediaPlayerEntity : public Entity
{
    Q_OBJECT
    QML_NAMED_ELEMENT(MediaPlayerEntity)

    Q_PROPERTY(int supportedFeatures MEMBER _supportedFeatures)     	                // Flag supported features.
    Q_PROPERTY(QString soundMode MEMBER _soundMode)     	                            // The current sound mode of the media player
    Q_PROPERTY(QStringList soundModeList MEMBER _soundModeList)     	                // Dynamic list of available sound modes(set by platform, empty means sound mode not supported)
    Q_PROPERTY(QString source MEMBER _source)     	                                    // The currently selected input source for the media player.
    Q_PROPERTY(QStringList sourceList MEMBER _sourceList)     	                        // The list of possible input sources for the media player. (This list should contain human readable names, suitable for frontend display)
    Q_PROPERTY(QString mediaImageUrl MEMBER _mediaImageUrl)     	                    // URL that represents the current image.
    Q_PROPERTY(bool mediaImageRemotelyAccessible MEMBER _mediaImageRemotelyAccessible)  // Return True if property media_image_url is accessible outside of the home network.
    Q_PROPERTY(QString deviceClass	 MEMBER _deviceClass)     	                        // Type of media player.
    Q_PROPERTY(QStringList groupMembers MEMBER _groupMembers)     	                    // A dynamic list of player entities which are currently grouped together for synchronous playback.If the platform has a concept of defining a group leader, the leader should be the first element in that list.

public:
    MediaPlayerEntity(QObject *parent=NULL);
    virtual ~MediaPlayerEntity();

public slots:
    virtual void playMedia()        {}
    virtual void browseMedia()      {}
    virtual void selectSoundMode()  {}
    virtual void selectSource()     {}


protected:
    int _supportedFeatures;
    QString _soundMode;
    QStringList _soundModeList;
    QString _source;
    QStringList _sourceList;
    QString _mediaImageUrl;
    bool _mediaImageRemotelyAccessible;
    QString _deviceClass;
    QStringList _groupMembers;
};

#endif

/* 

SUPPORTED FEATURES 

    BROWSE_MEDIA	        - Entity allows browsing media.
    CLEAR_PLAYLIST	        - Entity allows clearing the active playlist.
    GROUPING		        - Entity can be grouped with other players for synchronous playback.
    NEXT_TRACK		        - Entity allows skipping to the next media track.
    PAUSE		            - Entity allows pausing the playback of media.
    PLAY		            - Entity allows playing/resuming playback of media.
    PLAY_MEDIA		        - Entity allows playing media sources.
    PREVIOUS_TRACK		    - Entity allows returning back to a previous media track.
    REPEAT_SET		        - Entity allows setting repeat.
    SEEK		            - Entity allows seeking position during playback of media.
    SELECT_SOUND_MODE	    - Entity allows selecting a sound mode.
    SELECT_SOURCE	        - Entity allows selecting a source/input.
    SHUFFLE_SET	            - Entity allows shuffling the active playlist.
    STOP	                - Entity allows stopping the playback of media.
    TURN_OFF	            - Entity is able to be turned off.
    TURN_ON	                - Entity is able to be turned on.
    VOLUME_MUTE	            - Entity volume can be muted.
    VOLUME_SET	            - Entity volume can be set to specific levels.
    VOLUME_STEP	            - Entity volume can be adjusted up and down.

STATES

    OFF	                    - Entity is turned off and is not accepting commands until turned on.
    ON	                    - Entity is turned on, but no details on its state is currently known.
    IDLE	                - Entity is turned on and accepting commands, but currently not playing any media. Possibly at some idle home screen.
    PLAYING	                - Entity is currently playing media.
    PAUSED	                - Entity has an active media and is currently paused
    STANDBY	                - Entity is in a low power state, accepting commands.
    BUFFERING	            - Entity is preparing to start playback of some media

MEDIATYPE -- Required. Returns one of the values from the MediaType enum that matches the mediatype

    MediaType.MUSIC
    MediaType.TVSHOW
    MediaType.MOVIE
    MediaType.VIDEO
    MediaType.EPISODE
    MediaType.CHANNEL
    MediaType.PLAYLIST
    MediaType.IMAGE
    MediaType.URL
    MediaType.GAME
    MediaType.APP

DEVICE CLASSES

    TV	                - Device is a television type device.
    SPEAKER	            - Device is speakers or stereo type device.
    RECEIVER    	    - Device is audio video receiver type device taking audio and outputting to speakers and video to some display.

*/
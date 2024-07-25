#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <conio.h>
#define SONG_INFO 100
#define MAX 2

typedef struct {
	char title[SONG_INFO], album[SONG_INFO], singer[SONG_INFO], composer[SONG_INFO];
	int recording_co_id, year;
} songtype ;

void recordSongs(songtype *s);
void releaseSongs();
void updateTaylorSwiftSongs(songtype *songs);

int main () {
	
	int i;
	songtype s[MAX];
	songtype songs[MAX];
	
	for (i = 0; i<MAX; ++i) {
		printf("\n\tInput title: "); scanf(" %[^\n]s", s[i].title); fflush(stdin);
		printf("\tInput album: "); scanf(" %[^\n]s", s[i].album); fflush(stdin);
		printf("\tInput singer: "); scanf(" %[^\n]s", s[i].singer); fflush(stdin);
		printf("\tInput composer: "); scanf(" %[^\n]s", s[i].composer); fflush(stdin);
		printf("\tInput recording company ID: "); scanf("%d", &s[i].recording_co_id); fflush(stdin);
		printf("\tInput year: "); scanf("%d", &s[i].year); fflush(stdin);
		recordSongs(&s[i]);
		printf("\n\tTrack %d written. Press any key to continue...", i+1); getch(); system("cls");
	}
	releaseSongs();
	printf("\n\tPress any key to continue..."); getch(); system("cls");
	
	updateTaylorSwiftSongs(songs);
		
	return 0;
}

void recordSongs(songtype *s) {
	
	FILE *fp = fopen("songs.txt", "a");
	if (fp != NULL) {
		fwrite(s, sizeof(songtype), 1, fp);
		fclose(fp);
	}
	
}

void releaseSongs() {
	songtype release;
	
	FILE *fp = fopen("songs.txt", "r");
	printf("\n\t===== Released songs ===== \n");
	while (fread(&release, sizeof(songtype), 1, fp)) {
		printf("\n\tSong title: %s\n", release.title); fflush(stdout);
		printf("\tSong album: %s\n", release.album); fflush(stdout);
		printf("\tArtist: %s\n", release.singer); fflush(stdout);
		printf("\tComposer: %s\n", release.composer); fflush(stdout);
		printf("\tRecording Company ID: %d\n", release.recording_co_id); fflush(stdout);
		printf("\tYear of release: %d\n", release.year); fflush(stdout);
		printf("\n");
	}
	fclose(fp);
}

void updateTaylorSwiftSongs(songtype *songs) {
	
	FILE *fp = fopen("songs.txt", "r");
	
	if (fp != NULL) {
		printf("\nSuccess file OPENING!!\n");
		fread(songs, sizeof(songtype)*MAX, 1, fp);
		printf("\nFile has been read!\n");
	} else {
		printf("\nFile opening failed!\n");
		exit(1);
	}
	fclose(fp);
	
	int i;
	for (i = 0; i<MAX; ++i) {
		if (strcmp(songs[i].singer, "Taylor Swift") == 0) {
			printf("\nWassup Swifties!\n");
			songs[i].recording_co_id = 0;
			strset(songs[i].album, '\0');
			strcpy(songs[i].album, "The Eras");
		}
	}
	
	fp = fopen("songs.txt", "w");
	if (fp != NULL) {
		printf("\nSuccess file OPENING!!\n");
		fwrite(songs, sizeof(songtype)*MAX, 1, fp);
		printf("\nNew File Contents have been updated!\n");
	} else {
		printf("\nFile opening failed!\n");
		exit(1);
	}
	fclose(fp);
	printf("\n\tPress any key to continue..."); getch(); system("cls");
	releaseSongs();
}

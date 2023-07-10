#include "../headers/main.h"

#define INDEX_FILE_NAME "index.txt"
#define STOPWORDS_FILE_NAME "stopwords.txt"
#define GRAPH_FILE_NAME "graph.txt"
#define PAGES_DIR_NAME "pages"

__u_char buffer[255];

int main(int argc, char const *argv[])
{

  // INPUT FILES

  if (argc < 2)
  {
    printf("error: missing command line arguments\n");
    return 1;
  }

  const __u_char *index_file_path = (const __u_char *)malloc((strlen(argv[1]) + strlen(INDEX_FILE_NAME)) * sizeof(__u_char));
  const __u_char *stopwords_file_path = (const __u_char *)malloc((strlen(argv[1]) + strlen(STOPWORDS_FILE_NAME)) * sizeof(__u_char));
  const __u_char *graph_file_path = (const __u_char *)malloc((strlen(argv[1]) + strlen(GRAPH_FILE_NAME)) * sizeof(__u_char));
  const __u_char *pages_directory_path = (const __u_char *)malloc((strlen(argv[1]) + strlen(PAGES_DIR_NAME)) * sizeof(__u_char));

  strcat(index_file_path, argv[1]);
  strcat(stopwords_file_path, argv[1]);
  strcat(graph_file_path, argv[1]);
  strcat(pages_directory_path, argv[1]);

  strcat(index_file_path, INDEX_FILE_NAME);
  strcat(stopwords_file_path, STOPWORDS_FILE_NAME);
  strcat(graph_file_path, GRAPH_FILE_NAME);
  strcat(pages_directory_path, PAGES_DIR_NAME);

  FILE *index_file = fopen(index_file_path, "r");

  while (fscanf(index_file, "%s", buffer))
  {
    printf(buffer);
  }

  return 0;
}

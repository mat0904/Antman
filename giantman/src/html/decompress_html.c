/*
** EPITECH PROJECT, 2022
** B-CPE-110-LYN-1-1-antman-adrien.audiard
** File description:
** compress_html.c
*/

#include "../../include/prototype.h"

void write_src(result_t *result, char *str, int c)
{
    if (c == 1) {
        result->res[result->i] = *str;
        result->len += 1;
        result->i += 1;
        return;
    }
    for (int i = 0; str[i] != '\0'; i++) {
        result->res[result->i] = str[i];
        result->len += 1;
        result->i += 1;
    }
}

void print_spaces(result_t *result, char *buf, int *i)
{
    char c = ' ';
    for (int j = 0, z = 255 + buf[*i] - 128; j < z; j++) {
        write_src(result, &c, 1);
    }
    (*i)++;
}

void replace_buffer_with_src(result_t *result, buffer_t *buffer, char **src)
{
    for (int i = 0; i < buffer->len; i++) {
        if (buffer->buf[i - 1] == '\n' && buffer->buf[i] < -1)
            print_spaces(result, buffer->buf, &i);
        if (i == buffer->len)
            return;
        while (buffer->buf[i] == -1) {
            i++;
            write_src(result, &(buffer->buf[i]), 1);
            i++;
            write_src(result, &(buffer->buf[i]), 1);
            i++;
        }
        if (buffer->buf[i] < 0)
            write_src(result, src[255 + buffer->buf[i] - 127], 0);
        else
            write_src(result, &(buffer->buf[i]), 1);
    }
}

int decompress_html(int ac, char **av, char **sources)
{
    buffer_t *buffer = NULL;
    result_t *result = malloc(sizeof(result_t));
    if (result == NULL || init_buffer_struct(av, &buffer) == 84) {
        free(result);
        return 84;
    }
    if (buffer->len == 0) {
        free(result);
        return 0;
    }
    result->res = malloc(sizeof(char) * buffer->len * 2);
    result->len = 0;
    result->i = 0;
    replace_buffer_with_src(result, buffer, sources);
    write(1, result->res, result->len);
    free(result->res);
    free(result);
    free(buffer->buf);
    free(buffer);
    return 0;
}

int init_sources_html(int ac, char **av)
{
    char *sources[128] = {"function(a){", "function(a)", "function()", "style=",
    "href=", "class=", "title=", "function", "(){", "link",
    "<div ", "<sup ", "table", "tbody", "<script", "img", "<var ",
    "void", "<li>", "<ul>", "role=", "position", "line", "border", "right",
    "top", "left", "solid", "</div>", "transparent", "absolute", "</sup>"
    "null", "typeof", "this", "false", "true", "if(", "else", "for", "return",
    "html", "window", "document", "content=", "item", "type", "search", "event",
    "()", "mouse", "https://", "new", "prototype", "length", "width", "pointer",
    "src", "key", "catch", "index", "id=", "name", "text", "li=", "li", "align",
    "font", "head" , "SIZE", "call", "Google", "Wikipedia", "js",
    "color", "performance", "button", "app", "value", "org", "note", "</p>",
    "<p>", "<a ", "<span ", "reference", "upload", "mwe_player",
    "poster", "media", "toggle", "hidden", "none", "play",
    "<svg ", "</div>", "<button ", "view", "crossorigin=", "async", "integrity",
    "</body>", "<input ", "data", "<details ", "</details>", "<ul ",
    "</ul>", "nbsp", "class", "</", "css",
    "link=", "static", "page", "local", "background",
    "object", "video", "content", "http-equiv=", "http", "charset=", "<title ",
    "rel=", "</title>", "property=", "<body ", 0};
    return decompress_html(ac, av, sources);
}

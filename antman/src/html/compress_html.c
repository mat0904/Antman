/*
** EPITECH PROJECT, 2022
** B-CPE-110-LYN-1-1-antman-adrien.audiard
** File description:
** compress_html.c
*/

#include "../../include/prototype.h"

int switch_src_bis(result_t *result, char *buf, char **src, int *i)
{
    int i_ini = *i;
    int n = 0;
    int c = 128;
    if (buf[*i] > 'z' || (buf[*i] < 'a' && buf[*i] != '<' && buf[*i] != 'S'
        && buf[*i] != '(' && buf[*i] != 'G' && buf[*i] != 'W'))
        return 0;
    if (*i > 0)
        n = buf[(*i) - 1] == '\n' ? 1 : 0;
    for (int j = 0; src[j] != 0; j++) {
        c = j + 128;
        (*i) += src_cmp(buf, src[j], *i);
        if (i_ini != *i) {
            write_src(result, &c, n);
            return 1;
        }
    }
    return 0;
}

int switch_src(result_t *result, char *buf, char **src, int *i)
{
    int i_ini = *i;
    int space = 129;
    while (buf[i_ini - 1] == '\n' && buf[*i] == ' ') {
        space++;
        (*i)++;
        if (buf[*i] != ' ' || space == 254) {
            write_src(result, &space, 0);
            (*i)--;
            return 1;
        }
    }
    return switch_src_bis(result, buf, src, i);
}

void replace_buffer_with_src(result_t *result, buffer_t *buffer, char **src)
{
    int c = 255;
    int b;
    for (int i = 0, s = 0; i < buffer->len; i++, s = 0) {
        while (buffer->buf[i] < 0) {
            s = 1;
            write_src(result, &c, 0);
            b = buffer->buf[i];
            write_src(result, &b, 0);
            i++;
            b = buffer->buf[i];
            write_src(result, &b, 0);
            i++;
        }
        if (s == 0 && switch_src(result, buffer->buf, src, &i) == 0) {
            b = buffer->buf[i];
            write_src(result, &b, 0);
        }
        if (s == 1)
            i--;
    }
}

int compress_html(int ac, char **av, char **sources)
{
    buffer_t *buffer = NULL;
    result_t *result = malloc(sizeof(result_t));
    if (result == NULL || init_buffer_struct(av, &buffer) == 84)
        return 84;
    if (buffer->len == 0)
        return 0;
    result->res = malloc(sizeof(char) * buffer->len);
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
    return compress_html(ac, av, sources);
}
